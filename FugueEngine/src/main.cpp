#include<OOGL\oogl.hpp>
#include<SFML\System.hpp>
#include<SFML\Window.hpp>

#include<FugueEngine\Character.h>
#include<FugueEngine\Segment.h>
#include<FugueEngine\World.h>


int main()
{
	sf::VideoMode video = sf::VideoMode::getDesktopMode();
	sf::Window gameWindow(video, "SFML OpenGL", sf::Style::Fullscreen);
	oogl::ooglInit();
	oogl::Entity::setAspectRatio(oogl::Vec2<unsigned int>(video.width, video.height));
 

	bool running = true;
	while(running)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			running = false;

		gameWindow.display();
		glClear(GL_COLOR_BUFFER_BIT);
	}

	return 0;
}