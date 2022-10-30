#include <Shadow.h>

class ExampleLayer : public Shadow::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		SW_INFO("ExampleLayer::Update");
	}

	void OnEvent(Shadow::Event& event) override
	{
		SW_TRACE("{0}", event)
	}
};

class Sandbox : public Shadow::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Shadow::ImGuiLayer());
	}
	
	~Sandbox()
	{

	}
};

Shadow::Application* Shadow::CreateApplication()
{
	return new Sandbox();
}