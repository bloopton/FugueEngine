#include<OOGL\oogl.hpp>
#include<SFML\System.hpp>
#include<SFML\Window.hpp>

#include<FugueEngine\Character.h>
#include<FugueEngine\Segment.h>
#include<FugueEngine\World.h>

int main()
{
	sf::Window game(sf::VideoMode(800, 600, 32), "SFML OpenGL", sf::Style::Fullscreen);
	oogl::ooglInit();

	bool running = true;
	while(running)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			running = false;

		oogl::Entity::drawAll();
		game.display();
	}

	return 0;
}