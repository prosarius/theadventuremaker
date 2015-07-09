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
    for(auto n: this->nodes)
        if(node == n)
            return;
    this->nodes.push_back(node);
}
void Graph::addNodes(vector<Point> nodes) {
    for(auto n: nodes)
        this->addNode(n);
}
void Graph::addEdge(Edge edge) {
    for(auto e: this->edges)
        if(e == edge)
            return;
    this->edges.push_back(edge);
}
void Graph::addEdge(Point from, Point to) {
    this->addEdge(Edge(from, to));
}
void Graph::addEdges(vector<Edge> edges) {
    for(auto e: edges)
        this->addEdge(e);
}

/* getters */
vector<Edge> Graph::getEdges() const {
    return this->edges;
}

vector<Edge> Graph::getEdges(const Point p) const {
    vector<Edge> ret;
    for(auto e: this->edges) {
        if(e.getBegin() != p && e.getEnd() != p)
            continue;
        ret.push_back(e);
    }
    return ret;
}

vector<Point> Graph::getNodes() const {
    return this->nodes;
}

/* other methods */
list<Point> Graph::getShortestPath(Point source, Point sink) const {
    cout << "entering Dijkstra" << endl;

    /* initialize */
    list<Point> ret;
    map<Point, Point> predecessor;
    map<Point, signed int> minLength;
    set<Point> q;

    cout << "init minLength with -1" << endl;
    /* set length to infinite */
    for (auto n: this->nodes) {
        Point p;
        for(auto f: this->nodes)
            if(f == n){
                p = f;
                break;
            }

        minLength[p] = -1;
        cout << p << " : " << minLength[p] << endl;
    }

    /* just debugging */
    cout << "Edges:" << endl;
    for (auto e: this->edges)
        cout << e << endl;

    /* source length is zero */
    minLength[source] = 0;

    /* source is in queue */
    q.insert(source);



    while (!q.empty()) {
        /* find nearest node in queue */
        Point p;
        bool pIsSet = false;
        for(auto point: q) {
            cout << minLength[point] << " < " << minLength[p] << " ? ";
            if(!pIsSet or minLength[point] < minLength[p]) {
                cout << "True" << endl;
                p = point;
                pIsSet = true;
            } else {
                cout << "False" << endl;
            }
        }
        /* erase it from queue */
        for(auto it: q)
            if(it == p)
                q.erase(it);

        cout << "Point is " << p << endl;
        /* analize edges */
        for(auto e: this->getEdges(p)) {
            Point to;
            /* find corresponding node */
            if (e.getBegin() == p)
                to = e.getEnd();
            else
                to = e.getBegin();

            cout << "found corresponding node: " << to << endl << "\tshortest path is: " << minLength[to] << endl << "\tshorter path could be: " << minLength[p] + e.getMagnitude() << endl;

            /* if not visited yet, push_back into queue and set predecessor*/
            if(minLength[to] == -1) {
                cout << "not visited yet. push_back into q" << endl;
                q.insert(to);
                minLength[to] = minLength[p] + e.getMagnitude();
                predecessor[to] = p;
            }
            /* if length is lower, update length and predecessor */
            else if(minLength[to] > (minLength[p] + e.getMagnitude())) {
                minLength[to] = minLength[p] + e.getMagnitude();
                cout << "shorter Path found: " <<  minLength[to] << endl;
            }
        }
    }

    /* make list from predecessors */
    ret.push_front(sink);
    Point toPush = sink;
    while (toPush != source) {
        if(minLength[toPush] == -1)
            break;
        toPush = predecessor[toPush];
        cout << "predecessor to push: " << toPush << endl;
        ret.push_front(toPush);
    }
    cout << "leaving Dijkstra" << endl;
    return ret;
}

void Graph::clear() {
    this->edges.clear();
    this->nodes.clear();
}
