#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <OOGL/oogl.hpp>
#include <fstream>
#include <memory>
#include <string>

class World;
class Character
{
public:
	static std::unique_ptr<Character> load(std::ifstream&);
	
	virtual ~Character() {};
	virtual void draw() = 0;
	virtual void update(GLfloat) = 0;
	virtual void save(std::ofstream&) = 0;

protected:
	std::vector<std::vector<gl::Animation>> animations;
	enum Direction {UP = 0, DOWN, RIGHT, LEFT};
	int action, direction, maxHealth, health, attack, defense;
	gl::Vec2f position;
	std::string name;
	float speed;

	static gl::Vec2f getDirectionVec(int);
	virtual bool isColision() = 0;
	virtual void move(float);
};

typedef std::unique_ptr<Character> chrPtr;
#endif // !CHARACTER_H