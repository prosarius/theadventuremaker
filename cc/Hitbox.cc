#include "h/Hitbox.h"

void Hitbox::refactorEdges() {
    this->edges.clear();
    if (this->points.size() <= 1)
        return;

    Point *succ = NULL;
    for (auto p: this->points) {
        if (!succ) {
            succ = &p;
            continue;
        }
        this->edges.push_back(Edge(succ, *p));
        succ = &p;
    }

    this->edges.push_back(Edge(succ, this->points.front()));
}

void Hitbox::addPoint(const Point &p) {
    this->points.push_back(p);
    this->refactorEdges();
}

list<Point> Hitbox::getPoints() const {
    return this->points;
}

vector<Edge> Hitbox::getEdges() const {
    return this->edges;
}

bool Hitbox::collides(const Point &p) const {
    return this->collides(Edge(Point(-1,-1), p));
}

int Hitbox::collides(const Edge &e) const {
    int count = 0;
    for (auto ed: this->edges)
        if(ed.collides(e))
            count++;
}
