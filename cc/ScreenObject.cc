#include "../h/ScreenObject.h"

using namespace std;
/* Constructors */
ScreenObject::ScreenObject(const string &name, const int width, const int height, const int x, const int y, const string &texturePath, float pivotX, float pivotY, float hitboxWidth, float hitboxHeight)
	: name(name), size(width, height), position(x, y), pivot(pivotX, pivotY), screen(NULL) {
    this->hitbox.push_back(Point(x - hitboxWidth / 2, y - hitboxHeight / 2));
    this->hitbox.push_back(Point(x + hitboxWidth / 2, y - hitboxHeight / 2));
    this->hitbox.push_back(Point(x + hitboxWidth / 2, y + hitboxHeight / 2));
    this->hitbox.push_back(Point(x - hitboxWidth / 2, y + hitboxHeight / 2));
	this->animations.push_back(Animation("", texturePath, 60, this));
	this->setDefaultAnimation();
}

/* private functions */
void ScreenObject::setDefaultAnimation() {
	this->activeAnimation = &(this->animations.front());
}

/* setter */
void ScreenObject::addAnimation(Animation animation) {
	this->animations.push_back(animation);
	animation.addScreenObject(this);
}
void ScreenObject::addAnimation(const string &texturePath, int speed) {
	this->animations.push_back(Animation("", texturePath, speed, this));
}
void ScreenObject::addAnimation(const vector<string> &texturePaths, int speed) {
	this->animations.push_back(Animation("", texturePaths, speed, this));
}
void ScreenObject::addAnimations(vector<Animation> animations) {
	for(auto animation: animations) {
		animation.addScreenObject(this);
		this->animations.push_back(animation);
	}
}

void ScreenObject::setName(const string &name) {
	this->name = name;
}
void ScreenObject::setScreen(Screen* screen) {
	this->screen = screen;
}
void ScreenObject::setPivot(const float &x, const float &y) {
	this->pivot.setXY(x, y);
}


/* getter */
Animation* ScreenObject::getActiveAnimation() const {
	return this->activeAnimation;
}
string ScreenObject::getName() const {
	return this->name;
}
int ScreenObject::getPosX() const {
	return this->position.getX();
}
int ScreenObject::getPosY() const {
	return this->position.getY();
}
int ScreenObject::getWidth() const {
	return this->size.getX();
}
int ScreenObject::getHeight() const {
	return this->size.getY();
}
int ScreenObject::getRenderWidth() const {
    float factor = ((float)this->getPosY() / this->screen->getHeight()) * (1 - this->screen->getSizeFactor()) + this->screen->getSizeFactor() ;
    return this->getWidth() * factor;
}
int ScreenObject::getRenderHeight() const {
    float factor = ((float)this->getPosY() / this->screen->getHeight()) * (1 - this->screen->getSizeFactor()) + this->screen->getSizeFactor() ;
    return this->getHeight() * factor;
}
float ScreenObject::getPivotX() const {
    return this->pivot.getX();
}
float ScreenObject::getPivotY() const {
    return this->pivot.getY();
}
Screen* ScreenObject::getScreen() const {
	return this->screen;
}

vector<Point> ScreenObject::getHitbox() const {
    return hitbox;
}

/* other methods */
bool ScreenObject::greaterThan(ScreenObject* a, ScreenObject* b) {
    return (a->getPosY() < b->getPosY());
}

bool ScreenObject::collides(float x, float y) const{

    Point* out = NULL;

    for (auto p: this->hitbox.getPoints()) {
        if (!out) {
            out = new Point(p);
            continue;
        }
        if (out->getX() < p.getX())
            out->setX(p.getX());
        if (out->getY() < p.getY())
            out->setY(p.getY());
    }

    Edge ed(*out, Point(x, y));
    delete out;

    int cnt = 0;
    for (auto e: this->hitbox.getEdges())
        if (e.intersects(ed))
            cnt++;

    return (cnt & 1);
}

/* operators */

bool ScreenObject::operator==(const ScreenObject &o) const {
    return this->name == o.name && this->position == o.position;
}
