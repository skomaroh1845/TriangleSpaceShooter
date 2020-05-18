#ifndef SPACE_OBJECT
#define SPACE_OBJECT
#include "C:\Users\Skomaroh\Desktop\Primitives\Vector2D.h"

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
};
#endif // !SPACE_OBJECT