#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <FugueEngine/Character.hpp>
#include <SFML\Window.hpp>
#include <fstream>

class Player : public Character, public CanRun
{
public:
	Player();
	static objPtr load(std::ifstream&);
	virtual void save(std::ofstream&) const;
	virtual void update(float);

	static void loadReferences();
	static void releaseReferences();

protected:
	virtual void setCollision();
	virtual void stand(float);
	virtual void walk(float);
	virtual void run(float);
};
#endif