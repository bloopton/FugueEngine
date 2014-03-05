#include <FugueEngine\Player.hpp>
#include <FugueEngine\Segment.hpp>
#include <iostream>
#include <fstream>

std::vector<std::vector< gl::Animation>> Player::refrences;

Player::Player() {}

Player::Player(const std::string& file)
{
	std::ifstream saveFile(file);
	std::string line;

	std::getline(saveFile, line);
	name = line;

	int dir;
	saveFile >> dir;
	direction = (Direction)dir;

	saveFile >> position.x;
	saveFile >> position.y;

	for(auto& a : refrences)
		animations.push_back(a);

	currentAnimation = &animations[0][0];
}

void Player::update(float deltaTime)
{
	
}

void Player::draw()
{
	gl::setView(position * -1);
	currentAnimation->setPosition(position);
	currentAnimation->draw();
}

void Player::move(float deltaTime)
{

}


void Player::loadReferences()
{
	std::vector<gl::Animation> loadAnimations;
	std::string folder = "resources/characters/robot";
	gl::Rectangle rect(gl::Vec2f(), Segment::tileSize * 8);


	loadAnimations.push_back(gl::Animation(rect, folder + "/stand/front", 1, 500));
	loadAnimations.push_back(gl::Animation(rect, folder + "/stand/back", 1, 500));
	loadAnimations.push_back(gl::Animation(rect, folder + "/stand/right", 1, 500));
	loadAnimations.push_back(gl::Animation(rect, folder + "/stand/left", 1, 500));
	refrences.push_back(loadAnimations);
	loadAnimations.clear();


	loadAnimations.push_back(gl::Animation(rect, folder + "/walk/front", 4, 500));
	loadAnimations.push_back(gl::Animation(rect, folder + "/walk/back", 4, 500));
	loadAnimations.push_back(gl::Animation(rect, folder + "/walk/right", 4, 500));
	loadAnimations.push_back(gl::Animation(rect, folder + "/walk/left", 4, 500));
	refrences.push_back(loadAnimations);
	loadAnimations.clear();
}

void Player::releaseReferences()
{
	refrences.clear();
}