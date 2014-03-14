#include <FugueEngine\Player.hpp>
#include <FugueEngine\Segment.hpp>
#include <FugueEngine\World.hpp>
#include <iostream>
#include <fstream>

std::vector<std::vector< gl::Animation>> Player::refrences;


Player::Player() {}

Player::Player(std::ifstream& stream)
{
	animations = refrences;

	speed = 0.0004f;

	stream >> name;
	stream >> direction;
	stream >> position.x;
	stream >> position.y;
}


void Player::draw()
{
	animations[action][direction].draw();
}


void Player::update(float deltaTime)
{
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))	walk(deltaTime, UP);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))	walk(deltaTime, DOWN);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))	walk(deltaTime, RIGHT);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))	walk(deltaTime, LEFT);
	else stand();
		
	animations[action][direction].setPosition(position);
	gl::setView(position * -1);
}



bool Player::isColision()
{
	gl::Rectangle rect;
	if(direction == UP || direction == DOWN)
		rect = gl::Rectangle(gl::Vec2f(0, -World::tileSize * 3), gl::Vec2f(World::tileSize * 6.5f, World::tileSize * 2));
	else
		rect = gl::Rectangle(gl::Vec2f(0, -World::tileSize * 3), gl::Vec2f(World::tileSize * 4, World::tileSize * 2));

	rect.position += position;

	if(World::testCollsion(rect))
		return true;

	return false;
}


void Player::save(std::ofstream& stream)
{
	stream << "Player" << std::endl;
	stream << name << std::endl;
	stream << direction << std::endl;
	stream << position.x << std::endl;
	stream << position.y << std::endl;
}


void Player::loadReferences()
{
	gl::Rectangle bounds(gl::Vec2f(), World::tileSize * 8);
	
	std::vector<gl::Animation> loadAnimations;
	std::string folder = "resources/characters/robot";
	int fr = 550;

	loadAnimations.push_back(gl::Animation(bounds, folder + "/stand/up", 1, fr));
	loadAnimations.push_back(gl::Animation(bounds, folder + "/stand/down", 1, fr));
	loadAnimations.push_back(gl::Animation(bounds, folder + "/stand/right", 1, fr));
	loadAnimations.push_back(gl::Animation(bounds, folder + "/stand/left", 1, fr));
	refrences.push_back(loadAnimations);
	loadAnimations.clear();

	loadAnimations.push_back(gl::Animation(bounds, folder + "/walk/up", 4, fr));
	loadAnimations.push_back(gl::Animation(bounds, folder + "/walk/down", 4, fr));
	loadAnimations.push_back(gl::Animation(bounds, folder + "/walk/right", 4, fr));
	loadAnimations.push_back(gl::Animation(bounds, folder + "/walk/left", 4, fr));
	refrences.push_back(loadAnimations);
	loadAnimations.clear();

	for(auto& a : refrences)
		for(auto& b : a)
			b.run();
}

void Player::releaseReferences()
{
	refrences.clear();
}