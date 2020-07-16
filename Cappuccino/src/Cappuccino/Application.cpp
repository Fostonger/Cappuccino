#include "Application.h"

#include "Cappuccino/Log.h"
#include "Cappuccino/Events/ApplicationEvent.h"

namespace Cappuccino{
	Application::Application() {

	}

	Application::~Application() {
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			CP_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			CP_TRACE(e);
		}

		while (true);
	}
}