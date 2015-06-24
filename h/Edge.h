#ifndef EDGE_H
#define EDGE_H

#include "Point.h"

#include <math.h>
#include <string>
#include <iostream>

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
    friend ostream& operator<<(ostream &output, Edge &e);
    bool operator==(const Edge &e) const;

    /* getters */
    Point getBegin();
    Point getEnd();
    float getMagnitude();
};

#endif /* EDGE_H */
