#ifndef SPACE_BULLETS
#define SPACE_BULLETS

#include <cmath>
#include "Object.h"
#include <glut.h>
#include "SpaceShip.h"

class bullet : public Object {
private:
	T directional;
	int timer = 500;
public:
	bullet() {
		this->directional = T(0, 0);
		this->timer = 500;
		this->setColor(1, 0.5, 0);
		this->setCenter(T(-1, -1));
	};
	bullet(const T& directonal, const T& point) {
		this->directional = directonal;
		this->setColor(1, 0.5, 0);
		this->setCenter(point);
	};
	void print() const {
		glPointSize(6);
		glColor3f(1, 0.5, 0);
		glBegin(GL_POINTS);
		glVertex2f(this->getCenter().getX(), this->getCenter().getY());
		glEnd();
	};
	void moveForward(float x) {
		this->setCenter(this->getCenter() + (this->directional) * 0.25 * x);
		this->timer--;
		if (this->timer < 0) {
			this->directional = T(0, 0);
			this->timer = 500;
			this->setCenter(T(-1, -1));
		};
	};
	T getDirectional() const {
		return this->directional;
	};
	void operator = (const bullet& b) {
		this->directional = b.getDirectional();
		this->setColor(1, 0.5, 0);
		this->setCenter(b.getCenter() + this->directional);
		this->timer = 500;
	};

	void hit(const vector<SpaceShip>& S,const vector<Wall> walls) {
		for (auto it = walls.begin(); it != walls.end(); ++it) {
			T v1, v2, v3, v4;
			it->getRect(v1, v2, v3, v4);
			if (this->getCenter().getY() >= v3.getY() && this->getCenter().getY() <= v1.getY() &&
				this->getCenter().getX() >= v4.getX() && this->getCenter().getX() <= v2.getX()) {
				timer = 0;
			}
		}
		for (auto it = S.begin(); it != S.end(); ++it) {
			if (sqrt((this->getCenter() - it->getCenter()).getX() * (this->getCenter() - it->getCenter()).getX()
				+ (this->getCenter() - it->getCenter()).getY() * (this->getCenter() - it->getCenter()).getY())
				<= 3)
				timer = 0;
		}
	}
};

#endif // !SPACE_BULLETS
