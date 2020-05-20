#include "SpaceShip.h"
#include "Primitives.h"
#include <glut.h>
#include <cmath>
#include <iostream> //

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
	if (!this->death) A.print();
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

void SpaceShip::moveForward() {
	if (this->moveX) this->setCenter(T(this->getCenter().getX() + ((this->v3) * 0.25 * this->speed).getX(), this->getCenter().getY()));
	if (this->moveY) this->setCenter(T(this->getCenter().getX(), this->getCenter().getY() + ((this->v3) * 0.25 * this->speed).getY()));
	if (this->bullets < 3) {
		this->BulletTimer--;
	}
	if (this->BulletTimer < 1) {
		this->bullets++;
		this->BulletTimer = 300;
	} 
	if (this->SpeedTimer < 1 && this->SpeedTimer > -1) {
		this->speed = this->speed / 2;
		this->SpeedTimer = -2;
	}
	if (this->SpeedTimer >= 1) this->SpeedTimer--;
};

void SpaceShip::fire() {
	if (this->bullets > 0) --this->bullets;
};

T SpaceShip::getDirectional() const {
	return (this->v3 + this->getCenter());
};

char SpaceShip::getBullets() const {
	return this->bullets;
}

void SpaceShip::CanMove(const vector<Wall>& walls) {
	float hx = 999, hy = 999;
	char X, Y;
	for (auto it = walls.begin(); it != walls.end(); ++it) {
		if (it->getRotation() == 'H') {
			if ((abs(it->getCenter().getY() - this->getCenter().getY()) < hy) && 
				(this->getCenter().getX() < it->getCenter().getX() + it->getSize()/2) &&
				(this->getCenter().getX() > it->getCenter().getX() - it->getSize()/2)) {
				hy = abs(it->getCenter().getY() - this->getCenter().getY());
				if (it->getCenter().getY() > this->getCenter().getY()) Y = 'U';
				else Y = 'D';
			}
		}
		else {
			if (abs(it->getCenter().getX() - this->getCenter().getX()) < hx &&
				(this->getCenter().getY() < it->getCenter().getY() + it->getSize()/2) &&
				(this->getCenter().getY() > it->getCenter().getY() - it->getSize()/2)) {
				hx = abs(it->getCenter().getX() - this->getCenter().getX());
				if (it->getCenter().getX() > this->getCenter().getX()) X = 'R';
				else X = 'L';
			}
		}
	}

	this->moveY = false;
	this->moveX = false;

	if (hy > 4) this->moveY = true;
	else {
		float dY =this->getDirectional().getY() - this->getCenter().getY();
		if (Y == 'U' && dY < 0) this->moveY = true;
		if (Y == 'D' && dY > 0) this->moveY = true;
	}
	if (hx > 4) this->moveX = true;
	else {
		float dX = this->getDirectional().getX() - this->getCenter().getX();
		if (X == 'R' && dX < 0) this->moveX = true;
		if (X == 'L' && dX > 0) this->moveX = true;
	}
}

char SpaceShip::getKeyAction() const {
	return this->keyAction;
}

char SpaceShip::getKeyRotate() const {
	return this->keyRotate;
}

void SpaceShip::setDeath(bool death) {
	this->death = true;
};

void SpaceShip::UpSpeed() {
	if (this->SpeedTimer < 0) {
		this->speed = this->speed * 2;
		this->SpeedTimer = 300;
	}
}