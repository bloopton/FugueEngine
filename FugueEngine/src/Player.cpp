#include <FugueEngine\Player.hpp>
#include <FugueEngine\Segment.hpp>
#include <FugueEngine\World.hpp>
#include <iostream>
#include <fstream>

static AnimateSet refDrawStand, refDrawWalk, refDrawRun; 
static std::vector<gl::Vec2i> topBounds, bottomBounds, leftBounds, rightBounds;

Player::Player() : drawStand(refDrawStand), drawWalk(refDrawWalk)
{
	setDraw(drawStand[UP]);
	speed = .0002;
}


objPtr Player::load(std::ifstream& stream)
{
	std::unique_ptr<Player> Plyr(new Player());
	Plyr->loadInternal(stream);
	return static_cast<objPtr>(std::move(Plyr));
}


void Player::save(std::ofstream& stream) const
{
	stream << "Player" << std::endl;
	Character::saveInternal(stream);
}


void Player::update(float deltaTime)
{
	bool moves = false;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		setDirection(UP);
		moves = true;
	}
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		setDirection(DOWN);
		moves = true;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		setDirection(RIGHT);
		moves = true;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		setDirection(LEFT);
		moves = true;
	}

	if(moves == true)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) run(deltaTime);
		else walk(deltaTime);
	}
	else stand(deltaTime);

	gl::View::setPosition(getPosition() * -1);
}


void Player::stand(float deltaTime)
{
	drawStand[getDirection()].setPosition(getPosition());
	setDraw(drawStand[getDirection()]);
}

void Player::walk(float deltaTime)
{
	move(deltaTime, speed, getDirectionVec());
	
	if(getDirection() == UP || getDirection() == DOWN)
	{
		bool leftC = World::isCollosion(leftBounds, getPosition());
		bool rightC = World::isCollosion(rightBounds, getPosition());
		if(leftC || rightC) 
		{
			move(deltaTime, speed, getDirectionVec() * -1);
			if(leftC && !rightC) move(deltaTime, speed, getDirectionVec(RIGHT));
			if(rightC && !leftC) move(deltaTime, speed, getDirectionVec(LEFT));
		}
	}
	else if(getDirection() == LEFT || getDirection() == RIGHT)
	{
		bool topC = World::isCollosion(topBounds, getPosition());
		bool bottomC = World::isCollosion(bottomBounds, getPosition());

		if(topC || bottomC) 
		{
			move(deltaTime, speed, getDirectionVec() * -1);
			if(topC && !bottomC) move(deltaTime, speed, getDirectionVec(DOWN));
			if(bottomC && !topC) move(deltaTime, speed, getDirectionVec(UP));
		}
	}
	drawWalk[getDirection()].setPosition(getPosition());
	setDraw(drawWalk[getDirection()]);
}


void Player::run(float deltaTime)
{
	move(deltaTime, speed * 2, getDirectionVec());
	
	if(getDirection() == UP || getDirection() == DOWN)
	{
		bool leftC = World::isCollosion(leftBounds, getPosition());
		bool rightC = World::isCollosion(rightBounds, getPosition());
		if(leftC || rightC) 
		{
			move(deltaTime, speed * 2, getDirectionVec() * -1);
			if(leftC && !rightC) move(deltaTime, speed * 2, getDirectionVec(RIGHT));
			if(rightC && !leftC) move(deltaTime, speed * 2, getDirectionVec(LEFT));
		}
	}
	else if(getDirection() == LEFT || getDirection() == RIGHT)
	{
		bool topC = World::isCollosion(topBounds, getPosition());
		bool bottomC = World::isCollosion(bottomBounds, getPosition());

		if(topC || bottomC) 
		{
			move(deltaTime, speed * 2, getDirectionVec() * -1);
			if(topC && !bottomC) move(deltaTime, speed * 2, getDirectionVec(DOWN));
			if(bottomC && !topC) move(deltaTime, speed * 2, getDirectionVec(UP));
		}
	}
	drawWalk[getDirection()].setPosition(getPosition());
	setDraw(drawWalk[getDirection()]);
}

void Player::setCollision()
{

}


void Player::loadReferences()
{
	gl::Rectangle bounds(0, World::tileSize * 8);
	std::string folder = "resources/characters/robot";
	int fr = 650;

	refDrawStand[UP] = gl::Animation(bounds, folder + "/stand/up", 2, fr);
	refDrawStand[DOWN] = gl::Animation(bounds, folder + "/stand/down", 2, fr);
	refDrawStand[RIGHT] = gl::Animation(bounds, folder + "/stand/right", 2, fr);
	refDrawStand[LEFT] = gl::Animation(bounds, folder + "/stand/left", 2, fr);
	for(auto& a : refDrawStand) a.run();

	refDrawWalk[UP] = gl::Animation(bounds, folder + "/walk/up", 8, fr);
	refDrawWalk[DOWN] = gl::Animation(bounds, folder + "/walk/down", 8, fr);
	refDrawWalk[RIGHT] = gl::Animation(bounds, folder + "/walk/right", 8, fr);
	refDrawWalk[LEFT] = gl::Animation(bounds, folder + "/walk/left", 8, fr);
	for(auto& a : refDrawWalk) a.run();

	int runFR = 400;
	refDrawRun[UP] = gl::Animation(bounds, folder + "/walk/up", 8, runFR);
	refDrawRun[DOWN] = gl::Animation(bounds, folder + "/walk/down", 8, runFR);
	refDrawRun[RIGHT] = gl::Animation(bounds, folder + "/walk/right", 8, runFR);
	refDrawRun[LEFT] = gl::Animation(bounds, folder + "/walk/left", 8, runFR);
	for(auto& a : refDrawRun) a.run();


	leftBounds.push_back(gl::Vec2i(0, 2));
	leftBounds.push_back(gl::Vec2i(1, 2));
	for(int x = 2; x < 6; x++)
		for(int y = -1; y < 3; y++) leftBounds.push_back(gl::Vec2i(x, y));

	rightBounds.push_back(gl::Vec2i(6, 2));
	rightBounds.push_back(gl::Vec2i(7, 2));
	for(int x = 2; x < 6; x++)
		for(int y = -1; y < 3; y++) rightBounds.push_back(gl::Vec2i(x, y));


	for(int x = 2; x < 6; x++)
		for(int y = 2; y < 3; y++) topBounds.push_back(gl::Vec2i(x, y));
	for(int x = 2; x < 6; x++)
		for(int y = -1; y < 2; y++) bottomBounds.push_back(gl::Vec2i(x, y));

	for(auto& a : leftBounds) a -= 4;
	for(auto& a : rightBounds) a -= 4;
	for(auto& a : topBounds) a -= 4;
	for(auto& a : bottomBounds) a -= 4;
}

void Player::releaseReferences()
{
	
}