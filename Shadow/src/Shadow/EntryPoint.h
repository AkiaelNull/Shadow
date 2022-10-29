#pragma once

#ifdef SW_PLATFORM_WINDOWS

extern Shadow::Application* Shadow::CreateApplication();

int main(int argc, char** argv)
{
	Shadow::Log::Init();
	SW_CORE_WARN("Initialized Log!");
	int a = 5;
	SW_INFO("Hello! Var={0}", a);

	auto app = Shadow::CreateApplication();
	app->Run();
	delete app;
}

#endif
