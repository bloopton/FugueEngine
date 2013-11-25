#include<FugueEngine\World.h>

World::World()
{

}

World::World(std::vector<std::vector<Segment>> segMap, std::vector<Character> people , Character character)
	: worldMap(segMap), NPCS(people)
{
	
}