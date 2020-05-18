#include "SpaceShip.h"
#include "C:\Users\Skomaroh\Desktop\Primitives\Primitives.h"
#include <glut.h>

SpaceShip::SpaceShip(char keyRotate, char keyAction, const T& Center, float r, float g, float b) {
	this->keyRotate = keyRotate;
	this->keyAction = keyAction;
	this->setCenter(Center);
	this->setColor(r, g, b);
	this->v1 = T(-3, -3);
	this->v2 = T(3, -3);
	this->v3 = T(0, 4); //main vector
};

void SpaceShip::print() const {
	triangle A(this->v1 + this->getCenter(), this->v2 + this->getCenter(), this->v3 + this->getCenter());
	float r, g, b;
	this->getColor(r, g, b);
	A.setColor(r, g, b);
	A.print();
	if (this->bullets == 3) {
		glPointSize(6);
		glColor3f(1, 0.5, 0);
		glBegin(GL_POINTS);
			glVertex2f(this->v3.getX() + this->getCenter().getX(), this->v3.getY() + this->getCenter().getY());
			glVertex2f((this->v3 * 0.9 + this->v1 * 0.3).getX() + this->getCenter().getX(), (this->v3 * 0.9 + this->v1 * 0.3).getY() + this->getCenter().getY());
			glVertex2f((this->v3 * 0.9 + this->v2 * 0.3).getX() + this->getCenter().getX(), (this->v3 * 0.9 + this->v2 * 0.3).getY() + this->getCenter().getY());
		glEnd();
	}
	if (this->bullets == 2) {
		glPointSize(6);
		glColor3f(1, 0.5, 0);
		glBegin(GL_POINTS);
			glVertex2f(this->v3.getX() + this->getCenter().getX(), this->v3.getY() + this->getCenter().getY());
			glVertex2f((this->v3 * 0.9 + this->v1 * 0.3).getX() + this->getCenter().getX(), (this->v3 * 0.9 + this->v1 * 0.3).getY() + this->getCenter().getY());
		glEnd();
	}
	if (this->bullets == 1) {
		glPointSize(6);
		glColor3f(1, 0.5, 0);
		glBegin(GL_POINTS);
			glVertex2f(this->v3.getX() + this->getCenter().getX(), this->v3.getY() + this->getCenter().getY());
		glEnd();
	}
};

void SpaceShip::rotate(float angle) {
	this->v1.rotate(angle);
	this->v2.rotate(angle);
	this->v3.rotate(angle);
};

void SpaceShip::moveForward(float x) {
	this->setCenter(this->getCenter() + (this->v3) * 0.25 * x);
	if (this->bullets < 3) {
		this->BulletTimer--;
	}
	if (this->BulletTimer < 1) {
		this->bullets++;
		this->BulletTimer = 250;
	} 
};

void SpaceShip::fire() {
	if (this->bullets > 0) --this->bullets;
};

T SpaceShip::getDirectional() const {
	return this->v3;
};

char SpaceShip::getBullets() const {
	return this->bullets;
}