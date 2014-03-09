#include <FugueEngine\Player.hpp>
#include <FugueEngine\Segment.hpp>
#include <FugueEngine\World.hpp>
#include <iostream>
#include <fstream>

std::vector<std::vector< gl::Animation>> Player::refrences;
gl::Rectangle Player::bounds;
gl::Rectangle Player::wcBoundsY;
gl::Rectangle Player::wcBoundsX;


Player::Player() {}

Player::Player(const std::string& file)
{
	for(auto& a : refrences)
		animations.push_back(a);

	currentAnimation = &animations[0][0];
	speed = 0.0004;

	std::ifstream saveFile(file);
	saveFile >> name;
	int dir; saveFile >> dir; direction = (Direction)dir;
	saveFile >> position.x;
	saveFile >> position.y;
	saveFile.close();
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
		Direction prevDir = direction;
		direction = (Direction) keyPressed;
		if(isColision())
		{
			if(prevDir == RIGHT)
			{
				direction = LEFT;
				move(deltaTime);
				direction = RIGHT;
			}
			else
			{
				direction = RIGHT;
				move(deltaTime);
				direction = LEFT;
			}
		}
		else
			move(deltaTime);

		currentAnimation = &animations[1][direction];
	}
	else
		currentAnimation = &animations[0][direction];
	

	currentAnimation->setPosition(position);
	if(currentAnimation->getState() != gl::Animation::running)
		currentAnimation->run();

	gl::setView(position * -1);
}


void Player::draw()
{
	currentAnimation->draw();
}

std::string Player::save(const std::string& file)
{
	std::string saveFile = file + ".plr";
	std::ofstream saveStream(saveFile);
	saveStream.clear();
	saveStream << name << std::endl;
	saveStream << direction << std::endl;
	saveStream << position.x << std::endl;
	saveStream << position.y;
	saveStream.close();

	return saveFile;
}


bool Player::isColision()
{
	gl::Rectangle rect;
	if(direction == UP || direction == DOWN)
		rect = wcBoundsY;
	else
		rect = wcBoundsX;

	rect.position += position;

	if(Character::worldRef->testCollsion(rect))
		return true;
}


void Player::loadReferences()
{
	bounds = gl::Rectangle(gl::Vec2f(), World::tileSize * 8);
	wcBoundsY = gl::Rectangle(gl::Vec2f(0, -World::tileSize * 3), gl::Vec2f(World::tileSize * 6.5, World::tileSize * 2));
	wcBoundsX = gl::Rectangle(gl::Vec2f(0, -World::tileSize * 3), gl::Vec2f(World::tileSize * 4, World::tileSize * 2));

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
}

void Player::releaseReferences()
{
	refrences.clear();
}