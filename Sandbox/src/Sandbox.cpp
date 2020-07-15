#include "Cappuccino.h"

class Sandbox : public Cappuccino::Application {
public:
	Sandbox() {
		
	}

	~Sandbox() {

	}
};

Cappuccino::Application* Cappuccino::CreateApplication() {
	return new Sandbox();
}
