#ifndef SPACE_OBJECT
#define SPACE_OBJECT
#include "C:\Users\Skomaroh\Desktop\Primitives\Vector2D.h"
#include "C:\Users\Skomaroh\Desktop\Primitives\Primitives.h"

typedef Vector2D T;

class Object {
private:
	T CenterPoint;
	float red = 1, green = 1, blue = 1;
public:
	void setCenter(const T& V) {
		this->CenterPoint.setX(V.getX());
		this->CenterPoint.setY(V.getY());
	};
	void setColor(float r, float g, float b) {
		this->red = r;
		this->green = g;
		this->blue = b;
	};
	void getColor(float& r, float& g, float& b) const {
		r = this->red;
		g = this->green;
		b = this->blue;
	};
	T getCenter() const {
		return this->CenterPoint;
	}
	void moveUp(int x) {
		this->setCenter(Vector2D(this->getCenter().getX(), this->getCenter().getY() + x));
	};
	void moveDown(int x) {
		this->setCenter(Vector2D(this->getCenter().getX(), this->getCenter().getY() - x));
	};
	void moveLeft(int x) {
		this->setCenter(Vector2D(this->getCenter().getX() - x, this->getCenter().getY()));
	};
	void moveRight(int x) {
		this->setCenter(Vector2D(this->getCenter().getX() + x, this->getCenter().getY()));
	};
};
#endif // !SPACE_OBJECT