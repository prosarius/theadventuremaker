#include "../h/Graph.h"
#include <map>

using namespace std;

/* operators */
void Graph::operator+=(const Graph &g) {
    this->addNodes(g.nodes);
    this->addEdges(g.edges);
}

/* setters */
void Graph::addNode(Point node) {
    this->nodes.insert(node);
}
void Graph::addNodes(set<Point> nodes) {
    this->nodes.insert(nodes.begin(), nodes.end());
}
void Graph::addEdge(Edge edge) {
    this->edges.insert(edge);
}
void Graph::addEdge(Point from, Point to) {
    this->edges.insert(Edge(from, to));
}
void Graph::addEdges(set<Edge> edges) {
    this->edges.insert(edges.begin(), edges.end());
}

/* getters */
set<Edge*> Graph::getEdges(const Point* p) const {
    set<Edge*> ret;
    for(auto e: this->edges) {
        if(e.getBegin() != *p && e.getEnd() != *p)
            continue;
        ret.insert(&e);
    }
    return ret;
}

set<Point> Graph::getNodes() const {
    return this->nodes;
}

/* other methods */
list<Point> Graph::getShortestPath(Point source, Point sink) const {
    cout << "entering Dijkstra" << endl;
    const Point* sinkP = &(*(this->nodes.find(sink)));
    const Point* sourceP = &(*(this->nodes.find(source)));
    list<Point> ret;
    map<const Point*, const Point*> predecessor;
    map<const Point*, signed int> minLength;
    cout << "init minLength with -1" << endl;
    for (auto n: this->nodes) {
        const Point* p = &(*(this->nodes.find(n)));
        minLength[p] = -1;
        cout << "(" << p->getX() << "|" << p->getY() << ") : " << &n << " : " << p << " : " << minLength[p] << endl;
    }
    cout << "Edges:" << endl;
    for (auto e: this->edges) {
        cout << "(" << e.getBegin().getX() << "|" << e.getBegin().getY() << ")" << "\t(" << e.getEnd().getX() << "|" << e.getEnd().getY() << ")" << endl;
    }

    cout << "minLength[source] = 0" << endl;
    minLength[sourceP] = 0;
    set<const Point*> q;
    q.insert(sourceP);
    cout << "enterng while (!q.empty())" << endl;
    while (!q.empty()) {
        cout << "while..." << endl;
        const Point *p = NULL;
        for(auto point: q)
            if(!p || minLength[point] < minLength[p])
                p = point;
        for(auto it: q)
            if(&(*it) == p)
                q.erase(it);
        cout << "pop. q.size() is now " << q.size() << endl;
        cout << "Point is (" << p->getX() << "|" << p->getY() << ")" << ")" << endl;
        cout << "entering for(auto e: this->getEdges(p)). edges found: " << this->getEdges(p).size() << endl;
        for(auto e: this->getEdges(p)) {
            const Point* to = NULL;
            if(e->getBegin() == *p)
                to = &(*(this->nodes.find(e->getEnd())));
            else
                to = &(*(this->nodes.find(e->getBegin())));
            cout << "found corresponding node: (" << to->getX() << "|" << to->getY() << ") minLength[to]: " << minLength[to] << " : " << to << endl;
            if(minLength[to] == -1) {
                cout << "not visited yet. insert into q" << endl;
                q.insert(to);
                minLength[to] = e->getMagnitude();
                predecessor[to] = p;
            }
            else if(minLength[to] > minLength[p] + e->getMagnitude()) {
                cout << "already visited" << endl;
                minLength[to] = minLength[p] + e->getMagnitude();
            }
        }
    }
    cout << "leaving while (!q.empty())" << endl;

    ret.push_front(*sinkP);
    const Point* toPush = sinkP;
    cout << "entering while (toPush != sourceP)" << endl;
    while (toPush != sourceP) {
        cout << "while..." << endl;
        cout << "(" << toPush->getX() << "|" << toPush->getY() << ")";
        toPush = predecessor[toPush];
        cout << "\t(" << toPush->getX() << "|" << toPush->getY() << ")" << endl;
        ret.push_front(*toPush);
    }
    cout << "leaving Dijkstra" << endl;
    return ret;
}
