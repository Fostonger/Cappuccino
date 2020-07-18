#include "cappch.h"
#include "Application.h"

#include "Cappuccino/Log.h"

#include <GLFW/glfw3.h>

namespace Cappuccino{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(OnMouseMovedEvent));

		CP_CORE_TRACE("{0}",e);
	}

	void Application::Run() {
		
		while (m_Running) {
			glClearColor(m_Red, m_Green, m_Blue, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnMouseMovedEvent(MouseMovedEvent& e) {
		m_Red = (float)((int)e.GetX() % 256)/ 256.0;
		m_Blue = (float)((int)e.GetY() % 256)/256.0;
		CP_CORE_INFO("Colors now are: {0}, {1}", m_Red, m_Blue);
		
		return true;
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e) {
		m_Running = false;

		return true;
	}

}