#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Shadow {

	class SW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined int CLIENT
	Application* CreateApplication();

}