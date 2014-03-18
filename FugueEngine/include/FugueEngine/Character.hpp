#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <FugueEngine\GameObject.hpp>
#include <fstream>
#include <memory>
#include <string>

class World;
class Character : public GameObject
{
public:
	static std::unique_ptr<Character> load(std::ifstream&);
	virtual void save(std::ofstream&) = 0;

protected:
	std::string name;
	gl::Vec2i direction;
	gl::Vec2f position;
	float speed;
};

typedef std::unique_ptr<Character> chrPtr;
#endif