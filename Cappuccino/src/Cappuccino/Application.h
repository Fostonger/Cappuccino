#pragma once
#include "Core.h"
#include <stdio.h>
#include "Events/Event.h"

namespace Cappuccino {

	class CAP_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}

