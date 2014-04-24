#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <FugueEngine\GameObject.hpp>
#include <fstream>
#include <memory>
#include <string>
#include <array>

class World;
class Character : public GameObject, public Collidable, public Loadable
{
public:
	enum Direction { UP = 0, DOWN, RIGHT, LEFT };

private:
	std::string name;
	gl::Vec2f position;
	Direction direction;

protected:
	virtual void saveInternal(std::ofstream&) const;
	virtual void loadInternal(std::ifstream&);
	void move(float, float, gl::Vec2f);
	gl::Vec2f getPosition();
	Direction getDirection();
	void setDirection(Direction);
	gl::Vec2f getDirectionVec();
	gl::Vec2f getDirectionVec(Direction);
};


//Character Actions
typedef std::array<gl::Animation, 4> AnimateSet;

class CanStand
{
	protected: virtual void stand(float) = 0;
	public: virtual ~CanStand() {};
};
class CanWalk
{
	protected: virtual void walk(float) = 0;
	public: virtual ~CanWalk() {};
};
class CanRun
{
	protected: virtual void run(float) = 0;
	public: virtual ~CanRun() {};
};
#endif