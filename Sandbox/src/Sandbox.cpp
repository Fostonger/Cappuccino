#include "Cappuccino.h"

class Sandbox : public Cappuccino::Application {
public:
	Sandbox() {
		printf("sandboxes' only\n");
	}

	~Sandbox() {

	}
};

Cappuccino::Application* Cappuccino::CreateApplication() {
	return new Sandbox();
}
