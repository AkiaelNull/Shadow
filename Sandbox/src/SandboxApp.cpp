#include <Shadow.h>

class Sandbox : public Shadow::Application
{
public:
	Sandbox()
	{

	}
	
	~Sandbox()
	{

	}
};

Shadow::Application* Shadow::CreateApplication()
{
	return new Sandbox();
}