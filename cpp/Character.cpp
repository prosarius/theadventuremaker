#include "../h/Character.h"

/* constructors */
Character::Character(const string &name, const int &width, const int &height, const int &x, const int &y, const string &texturePath, const float &speed)
	: ScreenObject(name, width, height, x, y, texturePath), target(x, y), speed(speed) {
}

/* setters */
void Character::setPosition(const Position &position) {
	this->position = position;
}
void Character::setPosition(const float &x, const float &y) {
	this->position.setXY(x, y);
}
void Character::setTarget(const float &x, const float &y) {
	this->target.setXY(x, y);
}
void Character::setSpeed(const float &speed) {
	this->speed = speed;
}

/* getters */
Position* Character::getPosition() {
	return &(this->position);
}
float Character::getSpeed() const {
	return this->speed;
}


/* other methods */
void Character::tick() { /* If Charactr is in movement this function is called to do one step  */
	if(this->target.getX() == this->position.getX() && this->target.getY() == this->position.getY())
		return;
	Position distance = this->target - this->position;
    Position fak( (distance.getX() > 0) ? 1 : -1 , (distance.getY() > 0) ? 1 : -1 );
	/* pretend flickering and check for horizontal stop on screen */
	if(distance.getMagnitude() < 2 || (this->position.getY() - this->screen->getStopY() < 0.5 && fak.getY() == -1)){
		this->stopRunning();
		return;
	}
	if(!distance.getX())
		/* Just move in y direction */
		this->position.setXY(this->position.getX(), this->position.getY() + fak.getY() * this->speed);
	 else if(!distance.getY())
		/* Just move in x direction */
		this->position.setXY(this->position.getX() + fak.getX() * this->speed, this->position.getY());
	else
		/* move x and y */
		this->position.setXY(this->position.getX() + (float(distance.getX()) / distance.getMagnitude() * this->speed),
				this->position.getY() + (float(distance.getY()) / distance.getMagnitude() * this->speed));
}
void Character::startRunning() {
	this->getActiveAnimation()->startRunning();
}
void Character::stopRunning() {
	this->getActiveAnimation()->stopRunning();
	this->target = this->position;
}
