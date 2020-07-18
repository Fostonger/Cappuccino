#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Cappuccino/Events/ApplicationEvent.h"
#include "Cappuccino/Events/MouseEvent.h"

#include "Window.h"

namespace Cappuccino {

	class CAP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		float m_Red, m_Green, m_Blue = 1;
	};

	//To be defined in client
	Application* CreateApplication();
}

