#include "Cappuccino.h"

class ExampleLayer : public Cappuccino::Layer 
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void ExampleLayer::OnAttach() {
		CP_TRACE("Example Layer attached");
	}

	void OnUpdate() override
	{
		if (Cappuccino::Input::IsKeyPressed(CAP_KEY_TAB))
			CP_TRACE("Tab is being pressed");
	}

	void OnEvent(Cappuccino::Event& event) override
	{
		if (event.GetEventType() == Cappuccino::EventType::KeyPressed)
		{
			Cappuccino::KeyPressedEvent& e = (Cappuccino::KeyPressedEvent&)event;
			CP_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Cappuccino::Application 
{
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Cappuccino::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Cappuccino::Application* Cappuccino::CreateApplication() 
{
	return new Sandbox();
}
