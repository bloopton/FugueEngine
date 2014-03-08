#include <FugueEngine\FugueCore.hpp>

int main()
{
	sf::Window gameWindow;
	genWindow(&gameWindow);
	loadReferences();
	World world("saves/Ryan");
	Character::worldRef = &world;

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

	world.save();
	releseReferences();
	gl::ooglTerminate();
	return 0;
}