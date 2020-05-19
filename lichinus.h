#ifndef SPACE_LICHINUS
#define SPACE_LICHINUS

#include "Object.h"
#include "SpaceShip.h"

class lichinus : public Object {
private:
	T diractional;
	char keyRotate;
	char keyAction;
	char timer = 250;
	bool death = false;
public:
	lichinus(SpaceShip& ship);
	void print() const;
	void rotate();
	void moveForward(float x);
};

#endif // !SPACE_LICHINUS