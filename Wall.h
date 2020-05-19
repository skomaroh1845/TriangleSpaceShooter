#ifndef SPACE_WALL
#define SPACE_WALL
#include "Object.h"

class Wall : public Object {
private:
	rectangle Rect;
	T v1, v2, v3, v4;
	char Rotation;
public:
	Wall();
	void setWall(const T& center, float size, char rotation); // rotation: V = vertically or H = horizontally; size = length/2;
	void print();
	void rotate();
	void changeLength(int x);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	char getRotation() const;
};

#endif // !SPACE_WALL