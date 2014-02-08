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
	oogl::ooglInit();
	oogl::setAspectRatio(oogl::Vec2u(video.width, video.height));


	oogl::Texture baseTex("seg1\\base.png");
	oogl::Texture alphaTex("seg1\\alpha.png");
	Segment seg(baseTex, alphaTex, "seg1\\collisions.txt");

	Player dude("Robot");
	seg.addCharacter(dude);

	std::vector<std::vector<Segment>> map;
	std::vector<Segment> segs1;
	segs1.push_back(seg);

	map.push_back(segs1);

	World world(map);

	sf::Clock clock;
	float time = clock.getElapsedTime().asMilliseconds();

	bool running = true;
	while(running)
	{
		float deltaTime = clock.getElapsedTime().asMilliseconds() - time;
		time = clock.getElapsedTime().asMilliseconds();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			running = false;

		world.update(deltaTime);
		world.draw();

		
		gameWindow.display();
		glClear(GL_COLOR_BUFFER_BIT);
	}

	return 0;
}