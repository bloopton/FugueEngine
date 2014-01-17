#include <FugueEngine\Character.hpp>
#include <FugueEngine\Segment.hpp>


Character::Character()
{}

Character::Character(const Character& character)
	: speed(character.speed), direction(character.direction), action(character.action),
	currentSeg(character.currentSeg), leftTile(character.leftTile), rightTile(character.rightTile), 
	tilePosRight(character.tilePosRight), tilePosLeft(character.tilePosLeft), position(character.position), 
	animations(character.animations)
{}

Character::Character(std::string fileLocation)
	: currentSeg(0, 0), leftTile(0, 0), rightTile(0, 0), tilePosRight(0, 0), 
	tilePosLeft(Segment::tileSize, 0), position(Segment::tileSize/2.0f, Segment::tileSize/2.0f),
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


void Character::move(float deltaTime)
{
	float distance = speed * deltaTime;

	oogl::Vec2<int> 
		testRightTile = rightTile, 
		testLeftTile = leftTile;

	oogl::Vec2<GLfloat> 
		testTilePosRight = tilePosRight, 
		testTilePosLeft = tilePosLeft, 
		testPosition = position;

	if(direction == FRONT) 
	{
		testTilePosRight.y -= distance;
		testTilePosLeft.y  -= distance;
		testPosition.y     -= distance;
	}
	else if(direction == BACK) 
	{
		testTilePosRight.y += distance;
		testTilePosLeft.y  += distance;
		testPosition.y     += distance;
	}
	else if(direction == LEFT) 
	{
		testTilePosRight.x -= distance;
		testTilePosLeft.x  -= distance;
		testPosition.x     -= distance;
	}
	else if(direction == RIGHT) 
	{
		testTilePosRight.x += distance;
		testTilePosLeft.x  += distance;
		testPosition.x     += distance;
	}


	if(testTilePosLeft.y > Segment::tileSize)
	{
		testTilePosLeft.y -= Segment::tileSize;
		testLeftTile.y++;
	}
	if(testTilePosLeft.y < 0)
	{
		testTilePosLeft.y += Segment::tileSize;
		testLeftTile.y--;
	}
	if(testTilePosLeft.x > Segment::tileSize)
	{
		testTilePosLeft.x -= Segment::tileSize;
		testLeftTile.x++;
	}
	if(testTilePosLeft.x < 0)
	{
		testTilePosLeft.x += Segment::tileSize;
		testLeftTile.x--;
	}


	if(testTilePosRight.y > Segment::tileSize)
	{
		testTilePosRight.y -= Segment::tileSize;
		testRightTile.y++;
	}
	if(testTilePosRight.y < 0)
	{
		testTilePosRight.y += Segment::tileSize;
		testRightTile.y--;
	}
	if(testTilePosRight.x > Segment::tileSize)
	{
		testTilePosRight.x -= Segment::tileSize;
		testRightTile.x++;
	}
	if(testTilePosRight.x < 0)
	{
		testTilePosRight.x += Segment::tileSize;
		testRightTile.x--;
	}




	if(seg->isTileSolid(testRightTile) == false && seg->isTileSolid(testLeftTile) == false)
	{
		position = testPosition;
		tilePosRight = testTilePosRight;
		tilePosLeft = testTilePosLeft;
		rightTile = testRightTile;
		leftTile = testLeftTile;
	}
}


void Character::draw()
{
	if(animations[action][direction].isPaused())
		animations[action][direction].run();

	animations[action][direction].setPosition(position);
	animations[action][direction].draw();
}