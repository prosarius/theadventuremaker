#include "../h/Character.h"

Character::Character(string name, int width, int height, int x, int y, string texturePath)
	: ScreenObject(name, width, height, x, y, texturePath), target(150, 700) {
}

void Character::setPosition(Position position) {
	this->position = position;
}
void Character::setPosition(float x, float y) {
	this->position.setXY(x, y);
}
void Character::tick() {
	if(this->target.getX() == this->position.getX() && this->target.getY() == this->position.getY())
		return;
	int speed = 1;
	Position distance = Position(target.getX() - (this->getWidth()/2) - position.getX(), target.getY() - this->getHeight() - position.getY());
	Position fak( (distance.getX() > 0) ? 1 : -1 , (distance.getY() > 0) ? 1 : -1 );
	/* pretend flickering and check for horizontal stop on screen */
	if(distance.getMagnitude() < 0.5 || (this->position.getY() - this->screen->getStopY() < 0.5 && fak.getY() == -1)){
		this->stopRunning();
		return;
	}

	if(!distance.getX())
		/* Just move in y direction */
		this->position.setXY(this->position.getX(), this->position.getY() + fak.getY() * speed);
	 else if(!distance.getY())
		/* Just move in x direction */
		this->position.setXY(this->position.getX() + fak.getX() * speed, this->position.getY());
	else
		/* move x and y */
		this->position.setXY(this->position.getX() + (float(distance.getX()) / distance.getMagnitude() * float(speed)),
				this->position.getY() + (float(distance.getY()) / distance.getMagnitude() * float(speed)));

	this->resize();
}
void Character::resize(){
	/* resize
	 * toDo: get rid of hard coded shit
	 */
	float faktor = (900 - this->position.getY()) / (1200 - this->screen->getStopY());
	cout << faktor << endl;
	this->width = (1 - faktor) * 100;
	this->height = (1 - faktor) * 200;
}
void Character::setTarget(float x, float y) {
	this->target.setXY(x, y);
}
Position* Character::getPosition() {
	return &(this->position);
}
void Character::startRunning() {
	this->getActiveAnimation()->startRunning();
}
void Character::stopRunning() {
	this->getActiveAnimation()->stopRunning();
	this->target = this->position;
}
