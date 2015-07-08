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
