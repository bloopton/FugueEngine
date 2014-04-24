#include <FugueEngine\FugueCore.hpp>


void genWindow(sf::Window* window)
{
	sf::VideoMode video = sf::VideoMode::getDesktopMode();
	window->create(video, "Fugue");

	gl::ooglInit();
	gl::View::setAspectRatio(gl::Vec2u(video.width, video.height));
	window->setVerticalSyncEnabled(true);
}

void loadReferences()
{
	Player::loadReferences();
	Villager::loadReferences();
}

void releseReferences()
{
	Player::releaseReferences();
}