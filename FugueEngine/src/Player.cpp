#include <FugueEngine\Player.hpp>
#include <FugueEngine\Segment.hpp>
#include <OOGL\oogl.hpp>
#include<SFML\System.hpp>
#include<SFML\Window.hpp>


Player::Player() {}

Player::Player(const Player& player)
	: Character(player)
{
	speed = .0005;
}

Player::Player(const char* file)
	: Character(file)
{
	speed = .0005;
}


void Player::update(float deltaTime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction = BACK;
		action = WALK;
	}		
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction = FRONT;
		action = WALK;
	}	
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction = RIGHT;
		action = WALK;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction = LEFT;
		action = WALK;
	}
	else
	{
		action = STAND;
	}

	oogl::Entity::setView(position * -1.0f);
	
	if(action == WALK)
		move(deltaTime);
}