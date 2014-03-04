#include <FugueEngine\FugueCore.hpp>


int main()
{
	sf::Window gameWindow;
	genWindow(&gameWindow);
	loadReferences();

	World world("saves/save.sav");


	sf::Clock clock;
	float time = clock.getElapsedTime().asMilliseconds();
	
	bool running = true;
	while(running)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			running = false;

		float deltaTime = clock.getElapsedTime().asMilliseconds() - time;
		time = clock.getElapsedTime().asMilliseconds();

		world.update(deltaTime);
		world.draw();

		gameWindow.display();
		gl::clear();
	}

	releseReferences();
	gl::ooglTerminate();

	return 0;
}