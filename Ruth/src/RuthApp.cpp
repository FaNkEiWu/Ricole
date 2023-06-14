#include "rupch.h"
#include "Ricole.h"

class Ruth : public Ricole::Application {
	public:
		Ruth() {

		}

		~Ruth() {

		}
};

Ricole::Application* Ricole::CreateApplication() {
	return new Ruth();
}