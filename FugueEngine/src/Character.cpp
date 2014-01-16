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
	: currentSeg(0, 0), currentTile(0, 0), tilePos(Segment::tileSize/2.0f, 0), 
	position(Segment::tileSize/2.0f, Segment::tileSize/2.0f),
	animations(2, std::vector<oogl::Animation>()), action(STAND), direction(FRONT)
{
	oogl::Model model(oogl::Vec2<GLfloat>(0,0), (float)Segment::scale/(float)Segment::tiles);
	int fr = 600;

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

	oogl::Vec2<int> testCurrentSeg = currentSeg, testCurrentTile = currentTile;
	oogl::Vec2<GLfloat> testTilePos = tilePos, testPosition = position;

	if(direction == FRONT) 
	{
		testTilePos.y -= distance;
		testPosition.y -= distance;
	}
	else if(direction == BACK) 
	{
		testTilePos.y += distance;
		testPosition.y += distance;
	}
	else if(direction == RIGHT) 
	{
		testTilePos.x += distance;
		testPosition.x += distance;
	}
	else if(direction == LEFT) 
	{
		testTilePos.x -= distance;
		testPosition.x -= distance;
	}


	if(testTilePos.y > Segment::tileSize)
	{
		testTilePos.y -= Segment::tileSize;
		testCurrentTile.y++;
	}
	if(testTilePos.y < 0)
	{
		testTilePos.y += Segment::tileSize;
		testCurrentTile.y--;
	}
	if(testTilePos.x > Segment::tileSize)
	{
		testTilePos.x -= Segment::tileSize;
		testCurrentTile.x++;
	}
	if(testTilePos.x < 0)
	{
		testTilePos.x += Segment::tileSize;
		testCurrentTile.x--;
	}


	if(testCurrentTile.y > Segment::tiles)
	{
		testCurrentTile.y -= Segment::tiles;
		testCurrentSeg.y++;
	}
	if(testCurrentTile.y < 0)
	{
		testCurrentTile.y += Segment::tiles;
		testCurrentSeg.y--;
	}
	if(testCurrentTile.x > Segment::tiles)
	{
		testCurrentTile.x -= Segment::tiles;
		testCurrentSeg.x++;
	}
	if(testCurrentTile.x < 0)
	{
		testCurrentTile.x += Segment::tiles;
		testCurrentSeg.x--;
	}	


	if(seg->isTileSolid(testCurrentTile) == false)
	{
		position = testPosition;
		tilePos = testTilePos;
		currentTile = testCurrentTile;
		currentSeg = testCurrentSeg;
	}
}


void Character::draw()
{
	if(animations[action][direction].isPaused())
		animations[action][direction].run();

	animations[action][direction].setPosition(position);
	animations[action][direction].draw();
}