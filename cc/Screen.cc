#include "../h/Screen.h"

using namespace std;
Screen::Screen(const string &name, const int width, const int height, const int stopY, const float sizeFactor, const string &texturePath)
   	: name(name), size(width, height), stopY(stopY), sizeFactor(sizeFactor), backgroundPath(texturePath) {
}

/* setters */
void Screen::setWidth(const int &x) {
    this->size.setX(x);
}
void Screen::setHeight(const int &y) {
    this->size.setY(y);
}
void Screen::setStopY(const int &stopY) {
    this->stopY = stopY;
}
void Screen::setSizeFactor(const float &sizeFactor) {
    this->sizeFactor = sizeFactor;
}
void Screen::addPlayer(Character* character) {
	/* test if already added */
	if(find(this->screenObjects.begin(), this->screenObjects.end(), character) == this->screenObjects.end())
		this->screenObjects.push_back(character);
	this->player = character;
}
void Screen::addScreenObject(ScreenObject* screenObject) {
	this->screenObjects.push_back(screenObject);
	screenObject->setScreen(this);
}

/* getters */
int Screen::getWidth() const {
    return this->size.getX();
}
int Screen::getHeight() const {
    return this->size.getY();
}
string Screen::getName() const {
	return name;
}
int Screen::getStopY() const {
	return this->stopY;
}
Character* Screen::getPlayer() const {
	return this->player;
}
float Screen::getSizeFactor() const {
    return this->sizeFactor;
}
vector<ScreenObject*> Screen::getScreenObjects() const {
	return this->screenObjects;
}
string Screen::getBackgroundPath() const {
	return this->backgroundPath;
}

/* other methods */

void Screen::sortScreenObjects() {
    sort(this->screenObjects.begin(), this->screenObjects.end(), ScreenObject::greaterThan);
}

bool Screen::isWalkable(float x, float y) const {
    if(this->collidesWith(x, y))
        return false;
    return true;
}

Point Screen::getNearestPoint(float x, float y) const {
    ScreenObject* obj = this->collidesWith(x, y);
    if(!obj)
        return Point(x, y);

    Point target(x, y);
    Point retPos = target.getNearestPoint(0, obj->getPosX() - (obj->getHitboxWidth() / 2), true);

    Point temp = target.getNearestPoint(0, obj->getPosX() + (obj->getHitboxWidth() / 2), true);
    if((target - temp) < (target - retPos))
        retPos = temp;

    temp = target.getNearestPoint(0, obj->getPosY() - (obj->getHitboxHeight() / 2));
    if((target - temp) < (target - retPos))
        retPos = temp;

    temp = target.getNearestPoint(0, obj->getPosY() + (obj->getHitboxHeight() / 2));
    if((target - temp) < (target - retPos))
        retPos = temp;

    return retPos;
}

ScreenObject* Screen::collidesWith(float x, float y) const {
    for(auto obj: this->screenObjects)
        if(obj->collides(x, y))
            return obj;
    return NULL;
}

ScreenObject* Screen::collidesWith(Point from, Point to) const {
    ScreenObject* collidingObject = NULL;
    while (!collidingObject && from != to) {
        from.moveTo(to, 1);
        collidingObject = this->collidesWith(from.getX(), from.getY());
    }
    return collidingObject;
}

Graph Screen::buildGraph(Point from, Point to, set<ScreenObject*> *collidingObjects = NULL) {
    cout << "buildGraph is called" << endl;
    if(!collidingObjects) {
        cout << "\tfor the first time" << endl;
        set<ScreenObject*> objSet;
        collidingObjects = &objSet;
    }
    this->graph.clear();
    graph.addNode(from);
    graph.addNode(to);
    ScreenObject* collidingObject = this->collidesWith(from, to);
    if (!collidingObject) {
        graph.addEdge(from, to);
        cout << "buildGraph returns" << endl;
        return graph;
    }
    cout << "found colliding object: " << collidingObject->getName() << endl;
    collidingObjects->insert(collidingObject);
    vector<Point> points = collidingObject->getHitboxPoints();
    cout << "Hitbox points:" << endl;
    for (auto p: points) {
        cout << "(" << p.getX() << "|" << p.getY() << ")" << endl;
    }
    graph.addNodes(points);
    for (auto point: points) {
        cout << "Point: " << point << endl;
        /* edge from start */
        ScreenObject* collidingObject = this->collidesWith(from, point);
        if (!collidingObject) {
            graph.addEdge(from, point);
        }
        else if (collidingObjects->find(collidingObject) != collidingObjects->end())
            ; /* void */
        else
            graph += this->buildGraph(from, point, collidingObjects);

        /* edge to end */
        collidingObject = this->collidesWith(point, to);
        if (!collidingObject) {
            graph.addEdge(point, to);
        }
        else if (collidingObjects->find(collidingObject) != collidingObjects->end())
            ; /* void */
        else
            graph += this->buildGraph(point, to, collidingObjects);

        /* edges from node to node */
        for(auto sndPoint: points) {
            if (point == sndPoint)
                continue;
            ScreenObject* collidingObject = this->collidesWith(point, sndPoint);
            if (!collidingObject) {
                graph.addEdge(point, sndPoint);
            }
            else if (collidingObjects->find(collidingObject) != collidingObjects->end())
                ; /* void */
            else
                graph += this->buildGraph(point, sndPoint, collidingObjects);
        }
    }
    cout << "Nodes:" << endl;
    for (auto p: graph.getNodes()) {
        cout << "(" << p.getX() << "|" << p.getY() << ")" << endl;
    }
    cout << "buildGraph returns" << endl;
    return graph;
}

list<Point> Screen::getShortestWay(Point from, Point to) {
    Graph graph = this->buildGraph(from, to);
    list<Point> path = graph.getShortestPath(from, to);
    return path;
}
