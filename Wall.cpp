#include "Wall.h"
#include "C:\Users\Skomaroh\Desktop\Primitives\Primitives.h"
#include <glut.h>

Wall::Wall() {
	this->Rect.setEmpty(0);
	this->Rect.setColor(1, 0, 0);
	this->v1.setX(-2);
	this->v1.setY(+2);
	this->v2.setX(+2);
	this->v2.setY(+2);
	this->v3.setX(+2);
	this->v3.setY(-2);
	this->v4.setX(-2);
	this->v4.setY(-2);
	this->Rect.setV1(this->getCenter() + this->v1);
	this->Rect.setV2(this->getCenter() + this->v2);
	this->Rect.setV3(this->getCenter() + this->v3);
	this->Rect.setV4(this->getCenter() + this->v4);
} 

void Wall::setWall(const T& center, float size, char rotation) {
	this->setCenter(center);
	this->changeLength(size);
	this->Rotation = rotation;
	if (rotation == 'H') this->rotate();
}

void Wall::print() {
	this->Rect.setV1(this->getCenter() + this->v1);
	this->Rect.setV2(this->getCenter() + this->v2);
	this->Rect.setV3(this->getCenter() + this->v3);
	this->Rect.setV4(this->getCenter() + this->v4);
	this->Rect.print();
}

void Wall::rotate() {
	this->v1.rotate(90);
	this->v2.rotate(90);
	this->v3.rotate(90);
	this->v4.rotate(90);
	this->Rect.setV1(this->getCenter() + v1);
	this->Rect.setV2(this->getCenter() + v2);
	this->Rect.setV3(this->getCenter() + v3);
	this->Rect.setV4(this->getCenter() + v4);
};

void Wall::changeLength(int x) {
	this->v1.setY(this->v1.getY() + x);
	this->v2.setY(this->v2.getY() + x);
	this->v3.setY(this->v3.getY() - x);
	this->v4.setY(this->v4.getY() - x);
	this->Rect.setV1(this->getCenter() + v1);
	this->Rect.setV2(this->getCenter() + v2);
	this->Rect.setV3(this->getCenter() + v3);
	this->Rect.setV4(this->getCenter() + v4);
}

void Wall::moveUp() {
	this->Rect.moveUp(4);
	this->setCenter(T(this->getCenter().getX(), this->getCenter().getY() + 4));
}

void Wall::moveDown() {
	this->Rect.moveDown(4);
	this->setCenter(T(this->getCenter().getX(), this->getCenter().getY() - 4));
}

void Wall::moveLeft() {
	this->Rect.moveLeft(4);
	this->setCenter(T(this->getCenter().getX() - 4, this->getCenter().getY()));
}

void Wall::moveRight() {
	this->Rect.moveRight(4);
	this->setCenter(T(this->getCenter().getX() + 4, this->getCenter().getY()));
}

char Wall::getRotation() const {
	return this->Rotation;
}