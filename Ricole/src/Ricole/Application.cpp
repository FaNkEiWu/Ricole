#include "rcpch.h"
#include "Application.h"
#include "Ricole/Events/ApplicationEvent.h"
#include "Ricole/Log.h"

namespace Ricole
{
	Application::Application()
	{

	};

	Application::~Application()
	{

	};

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			RC_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			RC_TRACE(e);
		}

		while (true);
	};
}