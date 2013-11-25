#include<OOGL\oogl.hpp>
#include<SFML\System.hpp>
#include<SFML\Window.hpp>

#include<FugueEngine\Character.h>
#include<FugueEngine\Segment.h>
#include<FugueEngine\World.h>


int main()
{
	sf::VideoMode video = sf::VideoMode::getDesktopMode();
	sf::Window game(video, "SFML OpenGL", sf::Style::Fullscreen);
	oogl::ooglInit();
	oogl::Entity::setAspectRatio(oogl::Vec2<unsigned int>(video.width, video.height));

	Segment map = Segment(oogl::Texture("map.png"), "map.txt"); 

	bool running = true;
	while(running)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			running = false;


		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			map.translate(oogl::Vec2<GLfloat>(0, -.0005));
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			map.translate(oogl::Vec2<GLfloat>(0,  .0005));
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			map.translate(oogl::Vec2<GLfloat>(.0005, 0));
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			map.translate(oogl::Vec2<GLfloat>(-.0005, 0));

		map.draw();
		game.display();
		glClear(GL_COLOR_BUFFER_BIT);
	}

	return 0;
}