#pragma once

#include "Core.h"

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