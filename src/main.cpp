#include "main.hpp"

int main()
{
	Engine *app = new Engine(1280, 720);
	app->setup();
	app->loop();

	return 0;
}
