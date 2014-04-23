#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <FugueEngine\GameObject.hpp>
#include <fstream>
#include <memory>
#include <string>
#include <array>

class World;
class Character : public GameObject, public Movable, public Collidable, public Loadable
{
public:
	enum Direction { UP = 0, DOWN, RIGHT, LEFT };

protected:
	virtual void saveInternal(std::ofstream&) const;
	virtual void loadInternal(std::ifstream&);
	virtual void move(float, gl::Vec2f);
	gl::Vec2f getPosition();
	Direction getDirection();
	void setDirection(Direction);
	gl::Vec2f getDirectionVec();
	gl::Vec2f getDirectionVec(Direction);

private:
	std::string name;
	gl::Vec2f position;
	Direction direction;
	float speed;
};



//Character Behaviors
class CanStand
{
protected:
	std::array<gl::Animation, 4> drawStand;
	virtual void stand(float) = 0;
public:
	CanStand(const std::array<gl::Animation, 4>& ref) : drawStand(ref) {}
	virtual ~CanStand() {}
};

class CanWalk : public CanStand
{
protected:
	std::array<gl::Animation, 4> drawWalk;
	virtual void walk(float) = 0;
public:
	CanWalk(const std::array<gl::Animation, 4>& sRef, 
			const std::array<gl::Animation, 4>& ref	) : CanStand(sRef), drawWalk(ref) {}
	virtual ~CanWalk() {}
};

class CanRun : public CanWalk
{
protected:
	std::array<gl::Animation, 4> drawRun;
	virtual void run(float) = 0;
public:
	CanRun(	const std::array<gl::Animation, 4>& sRef,
			const std::array<gl::Animation, 4>& wRef,
			const std::array<gl::Animation, 4>& ref	) : CanWalk(sRef, wRef), drawRun(ref) {}
	virtual ~CanRun() {}
};
#endif