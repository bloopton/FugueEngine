#ifndef VILLAGER_HPP
#define VILLAGER_HPP

#include <FugueEngine/Character.hpp>
#include <SFML\Window.hpp>
#include <fstream>

class Villager : public Character, public CanStand, public CanWalk
{
public:
	enum Type {oldie, blondie, scarfie, traveler};

	Villager(Type);
	static objPtr load(std::ifstream&);
	virtual void save(std::ofstream&) const;
	virtual void update(float);

	static void loadReferences();
	static void releaseReferences();

protected:
	virtual void setCollision();
	virtual void stand(float);
	virtual void walk(float);

	AnimateSet drawStand, drawWalk;
	Type type;
	float speed;
};
#endif