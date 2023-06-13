#pragma once

#ifdef RC_PLATFORM_WINDOWS

extern Ricole::Application* Ricole::CreateApplication();

int main(int argc, char** argv) {
	auto app = Ricole::CreateApplication();
	app->Run();
	delete app;
}

#endif // RC_PLATFORM_WINDOWS
