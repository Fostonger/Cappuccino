#pragma once

#ifdef CAP_PLATFORM_WINDOWS

extern Cappuccino::Application* Cappuccino::CreateApplication();

int main(int argc, char** argv) {
	auto app = Cappuccino::CreateApplication();
	app->Run();
	delete app;
}
#endif