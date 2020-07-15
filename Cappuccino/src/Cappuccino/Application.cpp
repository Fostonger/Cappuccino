#include "Application.h"
#include "Cappuccino/Log.h"
#include "Cappuccino/Events/ApplicationEvent.h"

namespace Cappuccino{
	Application::Application() {

	}

	Application::~Application() {
	}

	void Application::Run() {
		WindowResizeEvent a(1080, 720);

		CP_TRACE(a);

		while (true);
	}
}