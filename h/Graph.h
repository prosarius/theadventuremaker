#ifndef GRAPH_H
#define GRAPH_H

#include "Point.h"
#include "Edge.h"
#include <vector>
#include <set>
#include <list>

using namespace std;
class Graph {
    vector<Point> nodes;
    vector<Edge> edges;

public:
    /* operators */
    void operator+=(const Graph &g);

    /* setters */
    void addNode(Point node);
    void addNodes(vector<Point> nodes);
    void addEdge(Edge edge);
    void addEdge(Point from, Point to);
    void addEdges(vector<Edge> edges);

    /* getters */
    vector<Edge> getEdges() const;
    vector<Edge> getEdges(const Point p) const;
    vector<Point> getNodes() const;

    /* other methods */
    list<Point> getShortestPath(Point source, Point sink) const;
    void clear();

};

#endif /* GRAPH_H */
