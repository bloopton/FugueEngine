#include<OOGL\oogl.hpp>
#include<SFML\System.hpp>
#include<SFML\Window.hpp>

#include<FugueEngine\Character.hpp>
#include<FugueEngine\Player.hpp>
#include<FugueEngine\Segment.hpp>
#include<FugueEngine\World.hpp>


int main()
{
	sf::VideoMode video = sf::VideoMode::getDesktopMode();
	sf::Window gameWindow(video, "SFML OpenGL");

	gl::ooglInit();
	gl::setAspectRatio(gl::Vec2u(video.width, video.height));



	sf::Clock clock;
	float time = clock.getElapsedTime().asMilliseconds();

	bool running = true;
	while(running)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			running = false;


		float deltaTime = clock.getElapsedTime().asMilliseconds() - time;
		time = clock.getElapsedTime().asMilliseconds();



		
		gameWindow.display();
		gl::clear();
	}


	gl::ooglTerminate();

	return 0;
}