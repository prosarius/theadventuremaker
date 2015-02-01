#include "../h/Character.h"
void Character::setPosition(Position position) {
	this->position = position;
}
void Character::setPosition(float x, float y) {
	this->position.setXY(x, y);
}
void Character::move(int direction) {
	float currX = this->position.getX();
	float currY = this->position.getY();
	if(this->direction != direction)
		this->turn(direction);
	if(direction | NORTHEAST)
		this->position.setXY(currX - 0.707, currY + 0.707);
	else if(direction | SOUTHEAST)
		this->position.setXY(currX + 0.707, currY + 0.707);
	else if(direction | SOUTHWEST)
	   	this->position.setXY(currX + 0.707, currY - 0.707);
	else if(direction | NORTHWEST)
	   	this->position.setXY(currX - 0.707, currY - 0.707);
	else if(direction | NORTH)
	   	this->position.setX(currX - 1);
	else if(direction | EAST)
	   	this->position.setY(currY + 1);
	else if(direction | SOUTH)
	   	this->position.setX(currX + 1);
	else if(direction | WEST)
	   	this->position.setY(currY - 1);
}
void Character::tick() {
	int speed = 2;
	Position distance = Position(target.getX() - position.getX(), target.getY() - position.getY());
	Position fak( (distance.getX() > 0) ? 1 : -1 , (distance.getY() > 0) ? 1 : -1 );
	Position newPosition = Position();
	if(distance.getMagnitude() < 0.05)
		; /* VOID */
	else if(!distance.getX())
		newPosition.setXY(this->position.getX(), this->position.getY() + fak.getY() * speed);
	 else if(!distance.getY())
		newPosition.setXY(this->position.getX() + fak.getX() * speed, this->position.getY());
	else
		newPosition.setXY(this->position.getX() + (float(distance.getX()) / distance.getMagnitude() * float(speed)),
				this->position.getY() + (float(distance.getY()) / distance.getMagnitude() * float(speed)));
	this->position = newPosition;
}
void Character::turn(int direction) {
	this->currentAnimation = this->directionAnimation.at(direction);
}
void Character::setTarget(float x, float y) {
	cout << "calling 'getX'" << endl;
	cout << this->position.getX();
	this->position.setXY(x, y);
}
Position* Character::getPosition() {
	return &(this->position);
}
int Character::getDirection() {
	return this->direction;
}
void Character::setDirection(int direction) {
	this->direction = direction;
}
