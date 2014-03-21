#include <FugueEngine\Player.hpp>
#include <FugueEngine\Segment.hpp>
#include <FugueEngine\World.hpp>
#include <iostream>
#include <fstream>

static std::array<gl::Animation, 4> refDrawStill, refDrawStillMove; 
static std::vector<gl::Vec2i> collisonBoundsV, collisonBoundsH;

Player::Player() {}

objPtr Player::load(std::ifstream& stream)
{
	std::unique_ptr<Player> Plyr(new Player());

	stream >> Plyr->name;
	stream >> Plyr->position.x;
	stream >> Plyr->position.y;
	stream >> Plyr->direction.x;
	stream >> Plyr->direction.y;
	stream >> Plyr->speed;
	Plyr->setAnimations();

	return static_cast<objPtr>(std::move(Plyr));
}

void Player::save(std::ofstream& stream) const
{
	stream << "Player" << std::endl;
	stream << name << std::endl;
	stream << position.x << std::endl;
	stream << position.y << std::endl;
	stream << direction.x << std::endl;
	stream << direction.y << std::endl;
	stream << speed << std::endl;
}


void Player::update(float deltaTime)
{
		 if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) move(deltaTime, Movable::UP);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) move(deltaTime, Movable::DOWN);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move(deltaTime, Movable::RIGHT);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move(deltaTime, Movable::LEFT);
	else setDraw(drawStill);

	gl::setView(position * -1);
}

void Player::move(float deltaTime, gl::Vec2f newDir)
{
	gl::Vec2f prevDir = direction;
	direction = newDir;
	if(isCollision())
	{
		Character::move(deltaTime, prevDir * -1);
		direction = prevDir;
	}
	else
		Character::move(deltaTime, direction);
}

bool Player::isCollision()
{
	gl::Vec2i tilePosition(GLint(position.x / World::tileSize), GLint(position.y / World::tileSize));
	std::vector<gl::Vec2i> testBounds;

	if(direction == Movable::UP || direction == Movable::DOWN)
		for(const auto& v : collisonBoundsV) testBounds.push_back(v + tilePosition);
	else 
		for(const auto& v : collisonBoundsH) testBounds.push_back(v + tilePosition);

	return World::testCollosion(testBounds);
}

void Player::setCollision()
{

}


void Player::setAnimations()
{
	drawStill = refDrawStill;
	drawMove  = refDrawStillMove;
	for(auto& a : drawStill) a.setPoint(position);
	for(auto& a : drawMove) a.setPoint(position);
	setDraw(drawStill);
}




void Player::loadReferences()
{
	gl::VertexArray bounds(gl::Vec2f(World::tileSize * 8), World::tileSize * 8);
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

	for(int i = -4; i <= 4; i++) collisonBoundsV.push_back(gl::Vec2i(i, -2));
	for(int i = -2; i <= 2; i++) collisonBoundsV.push_back(gl::Vec2i(i, -3));
	for(int i = -2; i <= 2; i++) collisonBoundsV.push_back(gl::Vec2i(i, -4));

	for(int i = -2; i <= 2; i++) collisonBoundsH.push_back(gl::Vec2i(i, -2));
	for(int i = -2; i <= 2; i++) collisonBoundsH.push_back(gl::Vec2i(i, -3));
	for(int i = -2; i <= 2; i++) collisonBoundsH.push_back(gl::Vec2i(i, -4));
}

void Player::releaseReferences()
{
	for(auto& a : refDrawStill) a.destroy();
	for(auto& a : refDrawStillMove) a.destroy();
}