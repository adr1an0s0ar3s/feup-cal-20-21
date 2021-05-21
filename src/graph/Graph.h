/*
 * Graph.h.
 * FEUP, CAL, 2017/18.
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include "MutablePriorityQueue.h"
#include "../util/Utils.h"
#include "Path.h"

using namespace std;

constexpr auto INF = std::numeric_limits<double>::max();

template <class T> class Vertex;
template <class T> class Edge;
template <class T> class Graph;

/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */

template <class T>
class Vertex {
private:

	T info;
	vector<Edge<T> *> outgoing;
	vector<Edge<T> *> incoming;

	bool visited;  // for path finding
	Edge<T> *path; // for path finding
	double dist;   // for path finding
	int queueIndex = 0; // required by MutablePriorityQueue

	Vertex(T info);
	void addEdge(Edge<T> *e);
	bool operator<(Vertex<T> &vertex) const; // required by MutablePriorityQueue

public:

	T getInfo() const;
	void setInfo(const T &info);
	vector<Edge<T> *> getIncoming() const;
	vector<Edge<T> *> getOutgoing() const;
	friend class Graph<T>;
	friend class MutablePriorityQueue<Vertex<T>>;

};

template <class T>
Vertex<T>::Vertex(T info): info(info) {}

template <class T>
void Vertex<T>::addEdge(Edge<T> *e) {
    outgoing.push_back(e);
    e->dest->incoming.push_back(e);
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {return this->dist < vertex.dist;}

template <class T>
T Vertex<T>::getInfo() const {return this->info;}

template <class T>
void Vertex<T>::setInfo(const T &info) {this->info = info;}

template <class T>
vector<Edge<T> *>  Vertex<T>::getIncoming() const {return this->incoming;}

template <class T>
vector<Edge<T> *>  Vertex<T>::getOutgoing() const {return this->outgoing;}

/*
 * ================================================================================================
 * Class Edge
 * ================================================================================================
 */

template <class T>
class Edge {
private:

    int id;
	Vertex<T> * orig;
	Vertex<T> * dest;
	double weight;

public:

    Edge(int id, Vertex<T> *o, Vertex<T> *d, double w);
	int getId() const;
    double getWeight() const;
    Vertex<T> *getOrig() const;
    Vertex<T> *getDest() const;
    bool operator<(const Edge<T> &edge) const;
    friend class Graph<T>;
    friend class Vertex<T>;

};

template <class T>
Edge<T>::Edge(int id, Vertex<T> *o, Vertex<T> *d, double w): id(id), orig(o), dest(d), weight(w) {}

template <class T>
int Edge<T>::getId() const {return id;}

template <class T>
double Edge<T>::getWeight() const {return weight;}

template <class T>
Vertex<T> *Edge<T>::getOrig() const {return orig;}

template <class T>
Vertex<T> *Edge<T>::getDest() const {return dest;}

template <class T>
bool Edge<T>::operator<(const Edge<T> &edge) const {return this->weight < edge.weight;}

/*
 * ================================================================================================
 * Class Graph
 * ================================================================================================
 */

template <class T>
class Graph {
private:

	vector<Vertex<T> *> vertexSet;

	Path dijkstraShortestPath(Vertex<T> *s, std::vector<Order> orders);
	void dfsVisit(Vertex<T> *s, std::vector<T> & res) const;
    std::vector<T> dfs() const;

public:

    Vertex<T> *addVertex(const T &in);
    Edge<T> *addEdge(int id, const T &sourc, const T &dest, double weight);
	Vertex<T>* findVertex(const T &inf) const;
    Vertex<T>* getVertex(int idx) const;
	vector<Vertex<T> *> getVertexSet() const;
	void clear();

};

template <class T>
Vertex<T> * Graph<T>::addVertex(const T &in) {
	Vertex<T> *v = findVertex(in);
	if (v != nullptr)
		return v;
	v = new Vertex<T>(in);
	vertexSet.push_back(v);
	return v;
}

template <class T>
Edge<T> * Graph<T>::addEdge(int id, const T &sourc, const T &dest, double weight) {
	auto s = findVertex(sourc);
	auto d = findVertex(dest);
	if (s == nullptr || d == nullptr)
		return nullptr;
	Edge<T> *e = new Edge<T>(id, s, d, weight);
	s->addEdge(e);
	return e;
}

template <class T>
Vertex<T>* Graph<T>::findVertex(const T & inf) const {
	for (auto v : vertexSet)
		if (v->info == inf)
			return v;
	return nullptr;
}

template <class T>
Vertex<T>* Graph<T>::getVertex(int idx) const {return vertexSet.at(idx);}

template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {return vertexSet;}

template <class T>
void Graph<T>::clear() {
    for (Vertex<T> *vertex: vertexSet) {
        for (Edge<T> *edge: vertex->getOutgoing()) delete edge;
        delete vertex;
    }
    vertexSet.clear();
}

template<class T>
Path Graph<T>::dijkstraShortestPath(Vertex<T> *s, std::vector<Order> orders) {
    Path path;

    while (!orders.empty()) {

        for (Vertex<T> *v: vertexSet) {
            v->dist = INF;
            v->path = NULL;
            v->visited = false;
        }

        s->dist = 0;

        MutablePriorityQueue<Vertex<T>> q;
        q.insert(s);

        while (!q.empty()) {
            Vertex<T> *temp = q.extractMin();

            if (temp->getInfo().getSupplier() != nullptr && supplyProducts(orders, temp->getInfo().getSupplier())) {
                break;
            }

            if (temp->getInfo().getClient() != nullptr && deliverProducts(orders, temp->getInfo().getClient())) {
                break;
            }

            for (Edge<T> w: temp->adj) {
                if (w.dest->dist > temp->dist + w.weight) {
                    w.dest->dist = temp->dist + w.weight;
                    w.dest->path = temp;
                    if (!w.dest->visited) {
                        w.dest->visited = true;
                        q.insert(w.dest);
                    } else q.decreaseKey(w.dest);
                }
            }
        }
    }
    return path;
}

/*
 * Performs a depth-first search (dfs) in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
std::vector<T> Graph<T>::dfs() const {
    std::vector<T> res;
    for (Vertex<T> *v : vertexSet)
        v->visited = false;
    for (Vertex<T> *v : vertexSet)
        if (!v->visited) dfsVisit(v, res);
    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent not yet visited, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, std::vector<T> & res) const {
    v->visited = true;
    res.push_back(v->info);
    for (Edge<T> *edge: v->outgoing)
        if (!edge->dest->visited) dfsVisit(edge->dest, res);
}

#endif /* GRAPH_H_ */
