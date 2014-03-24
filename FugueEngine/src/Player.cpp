#include <FugueEngine\Player.hpp>
#include <FugueEngine\Segment.hpp>
#include <FugueEngine\World.hpp>
#include <iostream>
#include <fstream>

static std::array<gl::Animation, 4> refDrawStand, refDrawWalk; 
static std::vector<gl::Vec2i> topBounds, bottomBounds, leftBounds, rightBounds;

Player::Player() 
{
	drawStand = refDrawStand;
	drawWalk = 
}

objPtr Player::load(std::ifstream& stream)
{
	std::unique_ptr<Player> Plyr(new Player());

	stream >> Plyr->name;
	stream >> Plyr->position.x;
	stream >> Plyr->position.y;
	int dir; stream >> dir; Plyr->direction = (Direction)dir;
	stream >> Plyr->speed;

	return static_cast<objPtr>(std::move(Plyr));
}

void Player::save(std::ofstream& stream) const
{
	stream << "Player" << std::endl;
	stream << name << std::endl;
	stream << position.x << std::endl;
	stream << position.y << std::endl;
	stream << direction << std::endl;
	stream << speed << std::endl;
}


void Player::update(float deltaTime)
{
	

	gl::setView(position * -1);
}


void Player::stand(float deltaTime)
{

}

void Player::walk(float deltaTime, Direction newDir)
{

}

bool Player::isCollision()
{
	return false;
}

void Player::setCollision()
{

}


void Player::loadReferences()
{
	gl::Rectangle bounds(gl::Vec2f(World::tileSize * 8), World::tileSize * 8);
	std::string folder = "resources/characters/robot";
	int fr = 550;

	refDrawStand[UP] = gl::Animation(bounds, folder + "/stand/up", 1, fr);
	refDrawStand[DOWN] = gl::Animation(bounds, folder + "/stand/down", 1, fr);
	refDrawStand[RIGHT] = gl::Animation(bounds, folder + "/stand/right", 1, fr);
	refDrawStand[LEFT] = gl::Animation(bounds, folder + "/stand/left", 1, fr);

	refDrawWalk[UP] = gl::Animation(bounds, folder + "/walk/up", 4, fr);
	refDrawWalk[DOWN] = gl::Animation(bounds, folder + "/walk/down", 4, fr);
	refDrawWalk[RIGHT] = gl::Animation(bounds, folder + "/walk/right", 4, fr);
	refDrawWalk[LEFT] = gl::Animation(bounds, folder + "/walk/left", 4, fr);


	
}

void Player::releaseReferences()
{
	
}