#include <FugueEngine\Player.hpp>
#include <FugueEngine\Segment.hpp>
#include <iostream>
#include <fstream>

std::vector<std::vector< gl::Animation>> Player::refrences;

Player::Player() {}

Player::Player(const std::string& file)
{
	for(auto& a : refrences)
		animations.push_back(a);

	currentAnimation = &animations[0][0];
	speed = 0.0005;

	std::ifstream saveFile(file);
	std::string line;

	std::getline(saveFile, line);
	name = line;

	int dir;
	saveFile >> dir;
	direction = (Direction)dir;

	saveFile >> position.x;
	saveFile >> position.y;
}

void Player::update(float deltaTime)
{
	int keyPressed = -1;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))		keyPressed = UP;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))		keyPressed = DOWN;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))		keyPressed = RIGHT;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))		keyPressed = LEFT;

	if(keyPressed != -1) 
	{
		direction = (Direction) keyPressed;
		move(deltaTime);

		currentAnimation = &animations[1][direction];
	}
	else
		currentAnimation = &animations[0][direction];
	

	currentAnimation->setPosition(position);
	currentAnimation->run();
	gl::setView(position * -1);
}


void Player::draw()
{
	currentAnimation->draw();
}


void Player::loadReferences()
{
	std::vector<gl::Animation> loadAnimations;
	std::string folder = "resources/characters/robot";

	gl::Rectangle rect(gl::Vec2f(), Segment::tileSize * 8);
	int fr = 300;


	loadAnimations.push_back(gl::Animation(rect, folder + "/stand/up", 1, fr));
	loadAnimations.push_back(gl::Animation(rect, folder + "/stand/down", 1, fr));
	loadAnimations.push_back(gl::Animation(rect, folder + "/stand/right", 1, fr));
	loadAnimations.push_back(gl::Animation(rect, folder + "/stand/left", 1, fr));
	refrences.push_back(loadAnimations);
	loadAnimations.clear();


	loadAnimations.push_back(gl::Animation(rect, folder + "/walk/up", 4, fr));
	loadAnimations.push_back(gl::Animation(rect, folder + "/walk/down", 4, fr));
	loadAnimations.push_back(gl::Animation(rect, folder + "/walk/right", 4, fr));
	loadAnimations.push_back(gl::Animation(rect, folder + "/walk/left", 4, fr));
	refrences.push_back(loadAnimations);
	loadAnimations.clear();
}

void Player::releaseReferences()
{
	refrences.clear();
}