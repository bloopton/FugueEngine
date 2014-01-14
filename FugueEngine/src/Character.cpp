#include <FugueEngine\Character.hpp>
#include <FugueEngine\Segment.hpp>


Character::Character()
{}

Character::Character(const Character& character)
	: speed(character.speed), direction(character.direction), action(character.action),
	currentSeg(character.currentSeg), currentTile(character.currentTile), tilePos(character.tilePos), 
	position(character.position), animations(character.animations)
{}

Character::Character(std::string fileLocation)
	: currentSeg(0, 0), currentTile(0, 0), tilePos(0, 0), 
	position(Segment::tileSize/2.0f, Segment::tileSize/2.0f),
	animations(2, std::vector<oogl::Animation>()), action(STAND), direction(FRONT)
{
	oogl::Model model(oogl::Vec2<GLfloat>(0,0), (float)Segment::scale/(float)Segment::tiles);
	int fr = 500;

	std::string currentFolder;

	currentFolder = fileLocation + "\\animations\\stand\\front\\";
	animations[STAND].push_back(oogl::Animation(model, currentFolder.c_str(), 1, fr)); 

	currentFolder = fileLocation + "\\animations\\stand\\back\\";
	animations[STAND].push_back(oogl::Animation(model, currentFolder.c_str(), 1, fr)); 

	currentFolder = fileLocation + "\\animations\\stand\\right\\";
	animations[STAND].push_back(oogl::Animation(model, currentFolder.c_str(), 1, fr)); 

	currentFolder = fileLocation + "\\animations\\stand\\left\\";
	animations[STAND].push_back(oogl::Animation(model, currentFolder.c_str(), 1, fr));



	currentFolder = fileLocation + "\\animations\\walk\\front\\";
	animations[WALK].push_back(oogl::Animation(model, currentFolder.c_str(), 4, fr)); 

	currentFolder = fileLocation + "\\animations\\walk\\back\\";
	animations[WALK].push_back(oogl::Animation(model, currentFolder.c_str(), 4, fr)); 

	currentFolder = fileLocation + "\\animations\\walk\\right\\";
	animations[WALK].push_back(oogl::Animation(model, currentFolder.c_str(), 4, fr)); 

	currentFolder = fileLocation + "\\animations\\walk\\left\\";
	animations[WALK].push_back(oogl::Animation(model, currentFolder.c_str(), 4, fr));
}


void Character::update(float deltaTime)
{
	//AI implementation
	move(deltaTime);
}


void Character::move(float deltaTime)
{
	float distance = speed * deltaTime;

	if(direction == FRONT) 
	{
		tilePos.y -= distance;
		position.y -= distance;
	}
	else if(direction == BACK) 
	{
		tilePos.y += distance;
		position.y += distance;
	}
	else if(direction == RIGHT) 
	{
		tilePos.x += distance;
		position.x += distance;
	}
	else if(direction == LEFT) 
	{
		tilePos.x -= distance;
		position.x -= distance;
	}


	if(tilePos.y > Segment::tileSize)
	{
		tilePos.y -= Segment::tileSize;
		currentTile.y++;
	}
	if(tilePos.y < 0)
	{
		tilePos.y += Segment::tileSize;
		currentTile.y--;
	}
	if(tilePos.x > Segment::tileSize)
	{
		tilePos.x -= Segment::tileSize;
		currentTile.x++;
	}
	if(tilePos.x < 0)
	{
		tilePos.x += Segment::tileSize;
		currentTile.x--;
	}


	if(currentTile.y > Segment::tiles)
	{
		currentTile.y -= Segment::tiles;
		currentSeg.y++;
	}
	if(currentTile.y < 0)
	{
		currentTile.y += Segment::tiles;
		currentSeg.y--;
	}
	if(currentTile.x > Segment::tiles)
	{
		currentTile.x -= Segment::tiles;
		currentSeg.x++;
	}
	if(currentTile.x < 0)
	{
		currentTile.x += Segment::tiles;
		currentSeg.x--;
	}
}


void Character::draw()
{
	if(animations[action][direction].isPaused())
		animations[action][direction].run();

	animations[action][direction].setPosition(position);
	animations[action][direction].draw();
}