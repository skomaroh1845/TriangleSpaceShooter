#ifndef SPACE_BULLETS
#define SPACE_BULLETS

#include "Object.h"
#include <glut.h>

class bullet : public Object {
private:
	T directional;
	int timer = 500;
public:
	bullet() {};
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
			this->setCenter(T(-1, 0));
		};
	};
	T getDirectional() const {
		return this->directional;
	};
	void operator = (const bullet& b) {
		this->directional = b.getDirectional();
		this->setColor(1, 0.5, 0);
		this->setCenter(b.getCenter() + this->directional);
	};
};

#endif // !SPACE_BULLETS
