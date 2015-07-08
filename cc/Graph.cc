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

    cout << "minLength[source] = 0" << endl;
    /* source length is zero */
    minLength[source] = 0;

    /* source is in queue */
    q.insert(source);



    cout << "enterng while (!q.empty())" << endl;
    while (!q.empty()) {
        cout << "while..." << endl;
        /* find nearest node in queue */
        Point p;
        bool pIsSet = false;
        for(auto point: q)
            if(!pIsSet or minLength[point] < minLength[p]) {
                p = point;
                pIsSet = true;
            }

        /* erase it from queue */
        for(auto it: q)
            if(it == p)
                q.erase(it);

        cout << "pop. q.size() is now " << q.size() << endl;
        cout << "Point is " << p << endl;
        cout << "entering for(auto e: this->getEdges(p)). edges found: " << this->getEdges(p).size() << endl;
        /* analize edges */
        for(auto e: this->getEdges(p)) {
            Point to;
            /* find corresponding node */
            if (e.getBegin() == p)
                for(auto n: this->nodes)
                    if(n == e.getEnd()) {
                        to = n;
                        break;
                    }
            else
                for(auto n: this->nodes)
                    if(n == e.getBegin()) {
                        to = n;
                        break;
                    }

            cout << "found corresponding node: " << to << " minLength[to]: " << minLength[to] << " : " << to << endl;
            /* if not visited yet, push_back into queue and set predecessor*/
            if(minLength[to] == -1) {
                cout << "not visited yet. push_back into q" << endl;
                q.insert(to);
                minLength[to] = e.getMagnitude();
                predecessor[to] = p;
            }
            /* if length is lower, update length and predecessor */
            else if(minLength[to] > minLength[p] + e.getMagnitude()) {
                cout << "already visited" << endl;
                minLength[to] = minLength[p] + e.getMagnitude();
            }
        }
    }
    cout << "leaving while (!q.empty())" << endl;

    /* make list from predecessors */
    ret.push_front(sink);
    Point toPush = sink;
    cout << "entering while (toPush != sourceP)" << endl;
    while (toPush != source) {
        cout << "while..." << endl << toPush << " --> ";
        toPush = predecessor[toPush];
        cout << toPush << endl;
        ret.push_front(toPush);
    }
    cout << "leaving Dijkstra" << endl;
    return ret;
}

void Graph::clear() {
    this->edges.clear();
    this->nodes.clear();
}
