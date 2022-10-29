#include "Application.h"

#include "Shadow/Events/ApplicationEvent.h"
#include "Shadow/Log.h"

namespace Shadow {

	Application::Application()
	{

	}
	
	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SW_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SW_TRACE(e);
		}

		while (true);
	}

}