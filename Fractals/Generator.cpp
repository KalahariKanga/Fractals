#include "Generator.h"


Generator::Generator()
{
}


Generator::~Generator()
{
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
		DrawContext* current = incompleteContexts.back();
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

	//for now im going to not try and subdivide space
	incompleteContexts.clear();
	incompleteContexts.push_back(context);
	worker();
}

