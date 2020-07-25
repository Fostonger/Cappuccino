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
		//CP_INFO("ExampleLayer: Update");
	}

	void OnEvent(Cappuccino::Event& event) override
	{
		CP_TRACE("Example layer's OnEvent");
		//CP_TRACE("{0}", event);
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
