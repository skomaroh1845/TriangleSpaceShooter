#ifndef SPACE_WALL
#define SPACE_WALL
#include "Object.h"

class Wall : public Object {
private:
	rectangle Rect;
	T v1, v2, v3, v4;
public:
	Wall();
	void print();
	void rotate();
	void changeLength(int x);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

#endif // !SPACE_WALL