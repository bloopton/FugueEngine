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

	currentAnimation = &animations[1][0];
}


void Player::update(float deltaTime)
{

}

void Player::draw()
{
	currentAnimation->draw();
}

void Player::move(float deltaTime)
{

}


void Player::loadReferences()
{
	std::vector<gl::Animation> loadAnimations;
	std::vector<gl::Texture> loadTextures;
	std::string folder = "resources/characters/robot";


	loadTextures.push_back(gl::Texture(folder + "/stand/front/1.png"));
	loadAnimations.push_back(gl::Animation(gl::Rectangle(gl::Vec2f(), Segment::tileSize * 16), loadTextures, 500));
	loadTextures.clear();
	loadTextures.push_back(gl::Texture(folder + "/stand/back/1.png"));
	loadAnimations.push_back(gl::Animation(gl::Rectangle(gl::Vec2f(), Segment::tileSize * 16), loadTextures, 500));
	loadTextures.clear();
	loadTextures.push_back(gl::Texture(folder + "/stand/right/1.png"));
	loadAnimations.push_back(gl::Animation(gl::Rectangle(gl::Vec2f(), Segment::tileSize * 16), loadTextures, 500));
	loadTextures.clear();
	loadTextures.push_back(gl::Texture(folder + "/stand/left/1.png"));
	loadAnimations.push_back(gl::Animation(gl::Rectangle(gl::Vec2f(), Segment::tileSize * 16), loadTextures, 500));
	loadTextures.clear();

	refrences.push_back(loadAnimations);
	loadAnimations.clear();


	loadTextures.push_back(gl::Texture(folder + "/walk/front/1.png"));
	loadTextures.push_back(gl::Texture(folder + "/walk/front/2.png"));
	loadTextures.push_back(gl::Texture(folder + "/walk/front/3.png"));
	loadTextures.push_back(gl::Texture(folder + "/walk/front/4.png"));
	loadAnimations.push_back(gl::Animation(gl::Rectangle(gl::Vec2f(), Segment::tileSize * 16), loadTextures, 500));
	loadTextures.clear();

	loadTextures.push_back(gl::Texture(folder + "/walk/back/1.png"));
	loadTextures.push_back(gl::Texture(folder + "/walk/back/2.png"));
	loadTextures.push_back(gl::Texture(folder + "/walk/back/3.png"));
	loadTextures.push_back(gl::Texture(folder + "/walk/back/4.png"));
	loadAnimations.push_back(gl::Animation(gl::Rectangle(gl::Vec2f(), Segment::tileSize * 16), loadTextures, 500));
	loadTextures.clear();

	loadTextures.push_back(gl::Texture(folder + "/walk/right/1.png"));
	loadTextures.push_back(gl::Texture(folder + "/walk/right/2.png"));
	loadTextures.push_back(gl::Texture(folder + "/walk/right/3.png"));
	loadTextures.push_back(gl::Texture(folder + "/walk/right/4.png"));
	loadAnimations.push_back(gl::Animation(gl::Rectangle(gl::Vec2f(), Segment::tileSize * 16), loadTextures, 500));
	loadTextures.clear();

	loadTextures.push_back(gl::Texture(folder + "/walk/left/1.png"));
	loadTextures.push_back(gl::Texture(folder + "/walk/left/2.png"));
	loadTextures.push_back(gl::Texture(folder + "/walk/left/3.png"));
	loadTextures.push_back(gl::Texture(folder + "/walk/left/4.png"));
	loadAnimations.push_back(gl::Animation(gl::Rectangle(gl::Vec2f(), Segment::tileSize * 16), loadTextures, 500));
	loadTextures.clear();

	refrences.push_back(loadAnimations);
	loadAnimations.clear();
}

void Player::releaseReferences()
{
	refrences.clear();
}