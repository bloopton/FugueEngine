#include <FugueEngine\Villager.hpp>
#include <FugueEngine\Segment.hpp>
#include <FugueEngine\World.hpp>
#include <array>
#include <iostream>
#include <fstream>
#include <math.h>

static std::array<gl::Animation, 4> refDrawStill, refDrawStillMove; 
static std::vector<gl::Vec2i> collisonBoundsV, collisonBoundsH;

Villager::Villager() {}

objPtr Villager::load(std::ifstream& stream)
{
	std::unique_ptr<Villager> Plyr(new Villager());

	stream >> Plyr->name;
	stream >> Plyr->position.x;
	stream >> Plyr->position.y;
	int dir; stream >> dir; Plyr->direction = (Direction)dir;
	stream >> Plyr->speed;
	Plyr->setAnimations();

	return static_cast<objPtr>(std::move(Plyr));
}

void Villager::save(std::ofstream& stream) const
{
	stream << "Villager" << std::endl;
	stream << name << std::endl;
	stream << position.x << std::endl;
	stream << position.y << std::endl;
	stream << direction << std::endl;
	stream << speed << std::endl;
}


void Villager::update(float deltaTime)
{
	


	move(deltaTime, direction);
}

void Villager::move(float deltaTime, gl::Vec2f newDir)
{
	
}

bool Villager::isCollision()
{
	return false;
}

void Villager::setCollision()
{

}


void Villager::setAnimations()
{
	
}




void Villager::loadReferences()
{
	gl::Rectangle bounds(gl::Vec2f(World::tileSize * 8), World::tileSize * 8);
	std::string folder = "resources/characters/robot";
	int fr = 550;

	refDrawStill[UP] = gl::Animation(bounds, folder + "/stand/up", 1, fr);
	refDrawStill[DOWN] = gl::Animation(bounds, folder + "/stand/down", 1, fr);
	refDrawStill[RIGHT] = gl::Animation(bounds, folder + "/stand/right", 1, fr);
	refDrawStill[LEFT] = gl::Animation(bounds, folder + "/stand/left", 1, fr);

	refDrawStillMove[UP] = gl::Animation(bounds, folder + "/walk/up", 4, fr);
	refDrawStillMove[DOWN] = gl::Animation(bounds, folder + "/walk/down", 4, fr);
	refDrawStillMove[RIGHT] = gl::Animation(bounds, folder + "/walk/right", 4, fr);
	refDrawStillMove[LEFT] = gl::Animation(bounds, folder + "/walk/left", 4, fr);

	for(int i = 2; i <= 6; i++) collisonBoundsV.push_back(gl::Vec2i(i, 0));
	for(int i = 2; i <= 6; i++) collisonBoundsV.push_back(gl::Vec2i(i, 1));
	for(int i = 0; i <= 8; i++) collisonBoundsV.push_back(gl::Vec2i(i, 2));

	for(int i = 2; i <= 6; i++) collisonBoundsH.push_back(gl::Vec2i(i, 0));
	for(int i = 2; i <= 6; i++) collisonBoundsH.push_back(gl::Vec2i(i, 1));
	for(int i = 2; i <= 6; i++) collisonBoundsH.push_back(gl::Vec2i(i, 2));
}

void Villager::releaseReferences()
{
	
}