#ifndef SPACE_BATTLE_SHIP
#define SPACE_BATTLE_SHIP

#include "Object.h"
#include <string>

using namespace std;

class SpaceShip : public Object {
private:
	char bullets = 3; // bullets
	unsigned char BulletTimer = 300; // respawn time 
	char keyRotate; //controling
	char keyAction; //controling
	bool mine = 0;    //bonuses
	bool swordz = 0;  // 
	bool shield = 1;  //
	bool lazer = 0;   //
	bool shoot = 0;   //
	bool death = false; // life
	T v1; // front
	T v2; // bag 
	T v3; // bag 
public:
	SpaceShip(char keyRotate, char keyAction, const T& Center, float r, float g, float b);
	void paint() const;
	void rotate(float angle);
	void moveForward(float x);
/*	void setBonus(string s);
	void getBonus(bool& mine, bool& sw, bool& sh, bool& lazer, bool& shoot) const;
	char getKeyAction() const;
	char getKeyRotate() const;
	void setDeath(bool death);*/
	T getDirectional() const; 
	void fire();
	char getBullets() const;
};

#endif // !SPACE_SHIP