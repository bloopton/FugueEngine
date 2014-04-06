#include <FugueEngine\FugueCore.hpp>

int main()
{ 
	sf::Window gameWindow;
	genWindow(&gameWindow);
	loadReferences();
	World world("saves/Ryan");

	sf::Clock clock;
	float time = float(clock.getElapsedTime().asMilliseconds());


	bool running = true;
	while(running)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			running = false;

		float deltaTime = clock.getElapsedTime().asMilliseconds() - time;
		time = float(clock.getElapsedTime().asMilliseconds());

		gl::View::setColor(gl::Vec3f(-.5, -.2, 0));

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