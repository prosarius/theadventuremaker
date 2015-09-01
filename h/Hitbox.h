#ifndef HITBOX_H
#define HITBOX_H

#include <list>
#include <vector>

#include "h/Point.h"
#include "h/Edge.h"


class Hitbox {
    list<Point> points;
    vector<Edge> edges;
    void refactorEdges();

public:
    void addPoint(const Point &p);
    void getPoints() const;
    vector<Edge> getEdges() const;
    bool collides(const Point &p) const;
    int collides(const Edge &e) const;
}




#endif /* HITBOX_H */
