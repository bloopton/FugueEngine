#include <FugueEngine\FugueCore.hpp>


void genWindow(sf::Window* window)
{
	sf::VideoMode video = sf::VideoMode::getDesktopMode();
	window->create(video, "Fugue");

	gl::ooglInit();
	gl::setAspectRatio(gl::Vec2u(video.width, video.height));
}

void loadReferences()
{
	Player::loadReferences();
}

void releseReferences()
{
	Player::releaseReferences();
}