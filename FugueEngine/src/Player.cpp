#include <FugueEngine\Player.hpp>
#include <FugueEngine\Segment.hpp>
#include <iostream>
#include <OOGL\oogl.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
 

Player::Player() {}

Player::Player(const Player& player)
	: Character(player)
{
	speed = .0004;
}

Player::Player(std::string file)
	: Character(file)
{
	speed = .0004;
}


void Player::update(float deltaTime)
{

}