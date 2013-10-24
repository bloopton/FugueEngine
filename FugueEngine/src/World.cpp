#include<FugueEngine\World.h>

World::World()
{

}

World::World(std::vector<std::vector<Segment>> segMap)
	: worldMap(segMap)
{


}