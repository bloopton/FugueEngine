#ifndef VILLAGER_HPP
#define VILLAGER_HPP

#include <FugueEngine/Character.hpp>
#include <SFML\Window.hpp>
#include <fstream>

class Villager : public Character
{
public:
	static void loadReferences();
	static void releaseReferences();

	Villager();
	static objPtr load(std::ifstream&);
	virtual void save(std::ofstream&) const;
	void move(float deltaTime, gl::Vec2f newDir);
	virtual bool isCollision();
	virtual void setCollision();
	virtual void update(float);

	virtual void setAnimations();
};
#endif