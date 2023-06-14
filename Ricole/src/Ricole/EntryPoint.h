#pragma once

#ifdef RC_PLATFORM_WINDOWS

extern Ricole::Application* Ricole::CreateApplication();

int main(int argc, char** argv)
{

	Ricole::Log::Init();

	RC_CORE_WARN("Inititalising logging");
	int a = 5;
	RC_INFO("HELLO{0}", a);

	auto app = Ricole::CreateApplication();
	app->Run();
	delete app;
};

#endif // RC_PLATFORM_WINDOWS
