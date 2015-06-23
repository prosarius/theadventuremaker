#ifndef EDGE_H
#define EDGE_H

#include "Point.h"

#include <math.h>

using namespace std;

class Edge {
    Point begin;
    Point end;
    float magnitude;
    float slope;

    void calcMagnitude();
public:
    Edge(Point begin, Point end);

    /* setters */
    void setBegin(Point begin);
    void setEnd(Point end);

    /* operators */
    bool operator<(const Edge &edge) const;

    /* getters */
    Point getBegin();
    Point getEnd();
    float getMagnitude();
};

#endif /* EDGE_H */
