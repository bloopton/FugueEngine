#include <Character.h>

	int level=1;
	int health=50;
	int maxHealth=50;
	int concentration=10;
	int maxConcentratio=10;
	int strength=1;
	int defense=1;
	int speed=1;
	int exp=1;
	int maxExp=2;

	void attack(Character attacker, Character defender)
	{
			if (direction = 0)//for attacking upwards
				{
					if (attacker.pos.y + 1 = defender.pos.y)
					{
						//play animation for attack
						defender.health = defender.health-attacker.attack/(2*defender.defense)

						if (health<0)
						{
							living=false;
							//play animation for death
						}
					}
				}
			
			
	};
	track();
	levelUp();