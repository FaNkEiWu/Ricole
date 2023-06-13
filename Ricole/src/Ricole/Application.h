#pragma once

#include "Core.h"

namespace Ricole {

	class RICOLE_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be defined in client
	Application* CreateApplication();
}

