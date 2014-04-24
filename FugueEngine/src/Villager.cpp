#include <FugueEngine\Villager.hpp>
#include <FugueEngine\Segment.hpp>
#include <FugueEngine\World.hpp>
#include <iostream>
#include <fstream>

static AnimateSet 
	refDrawStandBlondie, refDrawWalkBlondie,
	refDrawStandOldie, refDrawWalkOldie,
	refDrawStandScarfie, refDrawWalkScarfie,			  
	refDrawStandTraveler, refDrawWalkTraveler;

static std::vector<gl::Vec2i> topBounds, bottomBounds, leftBounds, rightBounds;

Villager::Villager(Type inType) : type(inType), speed(.0002)
{
	if(type == oldie)
	{
		drawStand = refDrawStandOldie;
		drawWalk = refDrawWalkOldie;
	}
	if(type == blondie)
	{
		drawStand = refDrawStandBlondie;
		drawWalk = refDrawWalkBlondie;
	}
	if(type == scarfie)
	{
		drawStand = refDrawStandScarfie;
		drawWalk = refDrawWalkScarfie;
	}
	if(type == traveler)
	{
		drawStand = refDrawStandTraveler;
		drawWalk = refDrawWalkTraveler;
	}

	setDraw(drawStand[UP]);
}


objPtr Villager::load(std::ifstream& stream)
{
	int typ; stream >> typ;
	std::unique_ptr<Villager> villager(new Villager((Type)typ));
	villager->loadInternal(stream);
	return static_cast<objPtr>(std::move(villager));
}


void Villager::save(std::ofstream& stream) const
{
	stream << "Villager" << std::endl;
	stream << type << std::endl;
	Character::saveInternal(stream);
}


void Villager::update(float deltaTime)
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

	if(moves == true) walk(deltaTime);
	else stand(deltaTime);

	gl::View::setPosition(getPosition() * -1);
}


void Villager::stand(float deltaTime)
{
	drawStand[getDirection()].setPosition(getPosition());
	setDraw(drawStand[getDirection()]);
}

void Villager::walk(float deltaTime)
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




void Villager::setCollision()
{

}


void Villager::loadReferences()
{
	gl::Rectangle bounds(0, World::tileSize * 8);
	std::string folder = "resources/characters/villager";
	int fr = 650;

	refDrawStandOldie[UP] = gl::Animation(bounds, folder + "/oldie/stand/up", 2, fr);
	refDrawStandOldie[DOWN] = gl::Animation(bounds, folder + "/oldie/stand/down", 2, fr);
	refDrawStandOldie[RIGHT] = gl::Animation(bounds, folder + "/oldie/stand/right", 2, fr);
	refDrawStandOldie[LEFT] = gl::Animation(bounds, folder + "/oldie/stand/left", 2, fr);
	for(auto& a : refDrawStandOldie) a.run();

	refDrawWalkOldie[UP] = gl::Animation(bounds, folder + "/oldie/walk/up", 4, fr);
	refDrawWalkOldie[DOWN] = gl::Animation(bounds, folder + "/oldie/walk/down", 4, fr);
	refDrawWalkOldie[RIGHT] = gl::Animation(bounds, folder + "/oldie/walk/right", 4, fr);
	refDrawWalkOldie[LEFT] = gl::Animation(bounds, folder + "/oldie/walk/left", 4, fr);
	for(auto& a : refDrawWalkOldie) a.run();



	refDrawStandBlondie[UP] = gl::Animation(bounds, folder + "/blondie/stand/up", 2, fr);
	refDrawStandBlondie[DOWN] = gl::Animation(bounds, folder + "/blondie/stand/down", 2, fr);
	refDrawStandBlondie[RIGHT] = gl::Animation(bounds, folder + "/blondie/stand/right", 2, fr);
	refDrawStandBlondie[LEFT] = gl::Animation(bounds, folder + "/blondie/stand/left", 2, fr);
	for(auto& a : refDrawStandBlondie) a.run();

	refDrawWalkBlondie[UP] = gl::Animation(bounds, folder + "/blondie/walk/up", 4, fr);
	refDrawWalkBlondie[DOWN] = gl::Animation(bounds, folder + "/blondie/walk/down", 4, fr);
	refDrawWalkBlondie[RIGHT] = gl::Animation(bounds, folder + "/blondie/walk/right", 4, fr);
	refDrawWalkBlondie[LEFT] = gl::Animation(bounds, folder + "/blondie/walk/left", 4, fr);
	for(auto& a : refDrawWalkBlondie) a.run();



	refDrawStandScarfie[UP] = gl::Animation(bounds, folder + "/scarfie/stand/up", 2, fr);
	refDrawStandScarfie[DOWN] = gl::Animation(bounds, folder + "/scarfie/stand/down", 2, fr);
	refDrawStandScarfie[RIGHT] = gl::Animation(bounds, folder + "/scarfie/stand/right", 2, fr);
	refDrawStandScarfie[LEFT] = gl::Animation(bounds, folder + "/scarfie/stand/left", 2, fr);
	for(auto& a : refDrawStandScarfie) a.run();

	refDrawWalkScarfie[UP] = gl::Animation(bounds, folder + "/scarfie/walk/up", 4, fr);
	refDrawWalkScarfie[DOWN] = gl::Animation(bounds, folder + "/scarfie/walk/down", 4, fr);
	refDrawWalkScarfie[RIGHT] = gl::Animation(bounds, folder + "/scarfie/walk/right", 4, fr);
	refDrawWalkScarfie[LEFT] = gl::Animation(bounds, folder + "/scarfie/walk/left", 4, fr);
	for(auto& a : refDrawWalkScarfie) a.run();



	refDrawStandTraveler[UP] = gl::Animation(bounds, folder + "/traveler/stand/up", 1, fr);
	refDrawStandTraveler[DOWN] = gl::Animation(bounds, folder + "/traveler/stand/down", 1, fr);
	refDrawStandTraveler[RIGHT] = gl::Animation(bounds, folder + "/traveler/stand/right", 1, fr);
	refDrawStandTraveler[LEFT] = gl::Animation(bounds, folder + "/traveler/stand/left", 1, fr);
	for(auto& a : refDrawStandTraveler) a.run();

	refDrawWalkTraveler[UP] = gl::Animation(bounds, folder + "/traveler/walk/up", 4, fr);
	refDrawWalkTraveler[DOWN] = gl::Animation(bounds, folder + "/traveler/walk/down", 4, fr);
	refDrawWalkTraveler[RIGHT] = gl::Animation(bounds, folder + "/traveler/walk/right", 4, fr);
	refDrawWalkTraveler[LEFT] = gl::Animation(bounds, folder + "/traveler/walk/left", 4, fr);
	for(auto& a : refDrawWalkTraveler) a.run();


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

void Villager::releaseReferences()
{
	
}