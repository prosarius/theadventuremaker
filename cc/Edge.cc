#include "../h/Edge.h"

using namespace std;
/* constructors */
Edge::Edge(Point begin, Point end) : begin(begin), end(end) {
    this->calcMagnitude();
}

/* setters */
void Edge::setBegin(Point begin) {
    this->begin = begin;
}
void Edge::setEnd(Point end) {
    this->end = end;
}

/* getters */
Point Edge::getBegin() const {
    return this->begin;
}
Point Edge::getEnd() const {
    return this->end;
}
float Edge::getMagnitude() const {
    return this->magnitude;
}

/* operators */
bool Edge::operator<(const Edge &edge) const {
    return edge.magnitude < this->magnitude;
}

ostream& operator<<(ostream &output, const Edge &e) {
    Point b = e.getBegin();
    Point end = e.getEnd();
    output << b << "---" << end;
    return output;
}

bool Edge::operator==(const Edge &e) const {
    cout << *this << " == " << e << "?" << endl;
    return (e.begin == this->begin && e.end == this->end) || (e.begin == this->end && e.end == this->begin);
}


/* other methods */
void Edge::calcMagnitude() {
	this->magnitude = sqrt(pow(this->begin.getX() - this->end.getX(), 2) + pow(this->begin.getY() - this->end.getY(), 2));
}

float Edge::getSlope() const {
    return (this->begin.getY() - this->end.getY()) / (this->begin.getX() - this->end.getX());
}

bool Edge::intersects(Edge e) {
    float m1 = this->getSlope();
    float m2 = e.getSlope();

    float n1 = this->begin.getY() - this->begin.getX() * m1;
    float n2 = e.begin.getY() - e.begin.getX() * m2;

    float x = (n2 - n1) / (m1 - m2);
    float y = m1 * x + n1;

    return    (x < this->begin.getX() && x > this->end.getX() || x > this->begin.getX() && x < this->end.getX())
           && (y < this->begin.getY() && y > this->end.getY() || y > this->begin.getY() && y < this->end.getY())
           && (x < e.begin.getX()     && x > e.end.getX()     || x > e.begin.getX()     && x < e.end.getX())
           && (y < e.begin.getY()     && y > e.end.getY()     || y > e.begin.getY()     && y < e.end.getY());
}
