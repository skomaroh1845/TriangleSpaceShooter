#include "Wall.h"
#include "C:\Users\Skomaroh\Desktop\Primitives\Primitives.h"
#include <glut.h>

Wall::Wall() {
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
	float r, g, b;
	this->getColor(r, g, b);
	this->Rect.setColor(r, g, b);
} 

void Wall::print() {
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
	this->v1.setX(this->v1.getX() + x);
	this->v2.setX(this->v2.getX() + x);
	this->v3.setX(this->v3.getX() - x);
	this->v4.setX(this->v4.getX() - x);
	this->Rect.setV1(this->getCenter() + v1);
	this->Rect.setV2(this->getCenter() + v2);
	this->Rect.setV3(this->getCenter() + v3);
	this->Rect.setV4(this->getCenter() + v4);
}

void Wall::moveUp() {
	this->Rect.moveUp(4);
	this->setCenter(Vector2D(this->getCenter().getX(), this->getCenter().getY() + 4));
}

void Wall::moveDown() {
	this->Rect.moveDown(4);
	this->setCenter(Vector2D(this->getCenter().getX(), this->getCenter().getY() - 4));
}

void Wall::moveLeft() {
	this->Rect.moveLeft(4);
	this->setCenter(Vector2D(this->getCenter().getX() - 4, this->getCenter().getY()));
}

void Wall::moveRight() {
	this->Rect.moveRight(4);
	this->setCenter(Vector2D(this->getCenter().getX() + 4, this->getCenter().getY()));
}