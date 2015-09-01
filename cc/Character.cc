#include "../h/Character.h"

/* constructors */
Character::Character(const string &name, const int &width, const int &height, const int &x, const int &y, const string &texturePath, float speed, float pivotX, float pivotY, float hitboxWidth, float hitboxHeight)
	: ScreenObject(name, width, height, x, y, texturePath, pivotX, pivotY, hitboxWidth, hitboxHeight), target(x, y), speed(speed) {
}

/* setters */
void Character::setPoint(const Point &position) {
	this->position = position;
}
void Character::setPoint(const float &x, const float &y) {
	this->position.setXY(x, y);
}
void Character::setTarget(const float &x, const float &y) {
    this->target = this->screen->getNearestPoint(x, y);
//    cout << "clicked: ( " << x << " | " << y << " )\ttarget: ( " << this->target.getX() << " | " << this->target.getY() << " )" << endl;
    list<Point> temp = this->screen->getShortestWay(this->position, this->target);
    cout << temp.size() << endl;
    for(auto n: temp)
        cout << n << endl;
    this->path = temp;
}
void Character::setSpeed(float speed) {
	this->speed = speed;
}

/* getters */
Point* Character::getPoint() {
	return &(this->position);
}
float Character::getSpeed() const {
	return this->speed;
}


/* other methods */
void Character::tick() { /* If Character is in movement this function is called to do one step  */
    if (this->target == this->position || this->path.empty()) {
        this->stopRunning();
        return;
    }
    Point front = this->path.front();
    Point distance = this->position - front;
    Point fak((distance.getX() >= 0) ? 1 : -1, (distance.getY() >= 0) ? 1 : -1);
    if (this->position == front) {
        this->path.pop_front();
        this->tick();
        return;
    }
    float factor = ((float)this->getPosY() / this->screen->getHeight()) * (1 - this->screen->getSizeFactor()) + this->screen->getSizeFactor();
    this->position.moveTo(front, this->speed * factor);
}
void Character::startRunning() {
	this->getActiveAnimation()->startRunning();
}
void Character::stopRunning() {
	this->getActiveAnimation()->stopRunning();
	this->target = this->position;
}
