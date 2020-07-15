#pragma once

#ifdef CAP_PLATFORM_WINDOWS

extern Cappuccino::Application* Cappuccino::CreateApplication();

int main(int argc, char** argv) {

	Cappuccino::Log::Init();
	CP_CORE_WARN("Inintialized Log");
	int a = 5;
	CP_INFO("Hi var={0}", a);

	auto app = Cappuccino::CreateApplication();
	app->Run();
	delete app;
}
#endif