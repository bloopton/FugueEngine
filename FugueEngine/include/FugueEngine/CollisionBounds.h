#ifndef COLLISIONBOUNDS_HPP
#define COLLISIONBOUNDS_HPP

#include <OOGL\oogl.hpp>
#include <vector>
#include <string>

class CollisionBounds
{
public:
	CollisionBounds();
	CollisionBounds(const std::string&)

private:
	std::vector<std::vector<gl::Vec2u>> solidTiles;

};
#endif // !COLLISIONBOUNDS_HPP
