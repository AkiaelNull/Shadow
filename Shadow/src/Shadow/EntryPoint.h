#pragma once

#ifdef SW_PLATFORM_WINDOWS

extern Shadow::Application* Shadow::CreateApplication();

int main(int argc, char** argv)
{
	printf("Shadow Engine");
	auto app = Shadow::CreateApplication();
	app->Run();
	delete app;
}

#endif
