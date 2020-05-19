#include "lichinus.h"

lichinus::lichinus(SpaceShip& ship) {
/*	this->keyAction = ship.getKeyAction();
	this->keyRotate = ship.getKeyRotate();
	this->setCenter(ship.getCenter());
	float r, g, b;
	ship.getColor(r, g, b);
	this->setColor(r, g, b);
	ship.setDeath(true);
	this->diractional = ship.getDirectional(); */
};

void lichinus::print() const {

}

void lichinus::rotate() {

}

void lichinus::moveForward(float x) {
	this->setCenter(this->getCenter() + (this->diractional * x));
}