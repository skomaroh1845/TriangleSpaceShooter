#ifndef SPACE_WALL
#define SPACE_WALL
#include "Object.h"

class Wall : public Object {
private:
	rectangle Rect;
	T v1, v2, v3, v4;
	char Rotation;
	float size;
public:
	Wall();
	Wall(const T& center, float size, char rotation);
	void setWall(const T& center, float size, char rotation); // rotation: V = vertically or H = horizontally; size = length/2;
	void print();
	void rotate();
	void changeLength(int x);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	char getRotation() const;
	float getSize() const;
	void getRect(T& v1, T& v2, T& v3, T& v4) const;
};

#endif // !SPACE_WALL