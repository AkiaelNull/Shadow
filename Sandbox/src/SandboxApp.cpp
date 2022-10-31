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
		if(Shadow::Input::IsKeyPressed(SW_KEY_TAB))
			SW_TRACE("Tab key pressed")

	}

	void OnEvent(Shadow::Event& event) override
	{
		if (event.GetEventType() == Shadow::EventType::KeyPressed)
		{
			Shadow::KeyPressedEvent& e = (Shadow::KeyPressedEvent&)event;
			SW_TRACE("{0}", (char)e.GetKeyCode());
		}
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