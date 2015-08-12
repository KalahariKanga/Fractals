#include "Generator.h"


Generator::Generator()
{
	workers = std::thread::hardware_concurrency();
	if (!workers)
		workers = 1;
	jobs = 20;
}


Generator::~Generator()
{
}

void Generator::subdivideContext()
{
	//split into vertical strips |||||||
	coord worldWidth = context->worldView.w / jobs;
	coord worldHeight = context->worldView.h;
	coord worldY = context->worldView.y;
	int screenWidth = context->screenView.w / jobs;

	for (int c = 0; c < jobs; c++)
	{
		View wView(context->worldView.x + c*worldWidth, worldY, worldWidth, worldHeight);
		View sView(context->screenView.x + c*screenWidth, context->screenView.y, screenWidth, context->screenView.h);
//		contexts.emplace_back(wView, sView);
//		contexts.push_back(DrawContext(wView, sView));
		contexts.push_back(std::make_shared<DrawContext>(wView, sView));

		incompleteContexts.push_back(std::shared_ptr<DrawContext>(contexts.back()));
	}
}

void Generator::worker()
{
	for (;;)
	{
		contextsMutex.lock();
		if (incompleteContexts.empty())
		{
			contextsMutex.unlock();
			return;
		}
		DrawContext* current = incompleteContexts.back().get();
		incompleteContexts.pop_back();
		contextsMutex.unlock();

		for (int cx = current->screenView.x; cx < current->screenView.x + current->screenView.w; cx++)
			for (int cy = current->screenView.y; cy < current->screenView.y + current->screenView.h; cy++)
				current->setPoint(cx, cy, ColourPalette::getColour(generatePoint(current->screenToWorld(cx, cy))));
	}
}

void Generator::run()
{
	/***************
	//populate contexts and incompleteContexts
	//start workers
	//wait for workers
	//merge contexts
	****************/
	
	auto start_time = std::chrono::high_resolution_clock::now();
	
	
	

	
	////for now im going to not try and subdivide space
	//incompleteContexts.clear();
	//incompleteContexts.push_back(context);
	//worker();
	

	contexts.clear();
	incompleteContexts.clear();
	
	subdivideContext();
	std::vector<std::thread> threads;
	for (int c = 0; c < workers; c++)
		threads.push_back(std::thread(&Generator::worker,this));
	for (auto &t : threads)
		t.join();
	for (auto dc : contexts)
		context->mergeContext(dc.get());

	auto end_time = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << "\n";
}

