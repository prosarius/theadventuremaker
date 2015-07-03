#ifndef GRAPH_H
#define GRAPH_H

#include "Point.h"
#include "Edge.h"
#include <set>
#include <list>

using namespace std;
class Graph {
    set<Point> nodes;
    set<Edge> edges;

public:
    /* operators */
    void operator+=(const Graph &g);

    /* setters */
    void addNode(Point node);
    void addNodes(set<Point> nodes);
    void addEdge(Edge edge);
    void addEdge(Point from, Point to);
    void addEdges(set<Edge> edges);

    /* getters */
    set<Edge> getEdges() const;
    set<Edge> getEdges(const Point p) const;
    set<Point> getNodes() const;

    /* other methods */
    list<Point> getShortestPath(Point source, Point sink) const;
    void clear();

};

#endif /* GRAPH_H */
