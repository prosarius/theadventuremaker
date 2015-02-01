#include "../h/Character.h"

Character::Character(int width, int height) : ScreenObject(width, height), target(0, 0) {
}
Character::Character(string name, int width, int height) : ScreenObject(name, width, height), target(0, 0) {
}
Character::Character(string name, int width, int height, string path) : ScreenObject(name, width, height, path), target(150, 700) {
}
Character::Character(string name, int width, int height, vector<string> paths) : ScreenObject(name, width, height, paths), target(0, 0) {
}
Character::Character(string name, int width, int height, Animation animation) : ScreenObject(name, width, height, animation), target(0, 0) {
}
Character::Character(string name, int width, int height, vector<Animation> animations) : ScreenObject(name, width, height, animations), target(0, 0) {
}
Character::Character(string name, int width, int height, vector<vector<string>> paths) : ScreenObject(name, width, height, paths), target(0, 0) {
}

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
	int speed = 1;
	Position distance = Position(target.getX() - (this->getWidth()/2) - position.getX(), target.getY() - this->getHeight() - position.getY());
	Position fak( (distance.getX() > 0) ? 1 : -1 , (distance.getY() > 0) ? 1 : -1 );
	if(distance.getMagnitude() < 0.5 )
		this->stopRunning();
	else if(!distance.getX())
		this->position.setXY(this->position.getX(), this->position.getY() + fak.getY() * speed);
	 else if(!distance.getY())
		this->position.setXY(this->position.getX() + fak.getX() * speed, this->position.getY());
	else
		this->position.setXY(this->position.getX() + (float(distance.getX()) / distance.getMagnitude() * float(speed)),
				this->position.getY() + (float(distance.getY()) / distance.getMagnitude() * float(speed)));
}
void Character::turn(int direction) {
	this->currentAnimation = this->directionAnimation.at(direction);
}
void Character::setTarget(float x, float y) {
	this->target.setXY(x, y);
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
void Character::startRunning() {
	this->getActiveAnimation()->startRunning();
}
void Character::stopRunning() {
	this->getActiveAnimation()->stopRunning();
}