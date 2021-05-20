#include "GUI.h"

using Nd = GraphViewer::Node;
using Ed = GraphViewer::Edge;

GUI::GUI(const Graph<Node> * graph, int width, int height): graph(graph), width(width), height(height), gv(new GraphViewer()) {

    gv->setCenter(sf::Vector2f(width/2,height/2));

    for (Vertex<Node> *vertex: graph->getVertexSet()) {
        // Add node
        Nd &node = gv->addNode(vertex->getInfo().getNodeId(), sf::Vector2f(vertex->getInfo().getX(), vertex->getInfo().getY()));

        if (vertex->getInfo().getClient() != nullptr) {         // If a vertex is a Client
            node.setLabel(vertex->getInfo().getClient()->getName());
            node.setSize(100);
            node.setColor(sf::Color::Red);
        } else if (vertex->getInfo().getSupplier() != nullptr) {  // If a vertex is a Supplier
            node.setLabel("Supplier");
            node.setSize(100);
            node.setColor(sf::Color::Green);
        } else {
            node.setSize(0);
        }
    }

    int id = 0;
    for (Vertex<Node> *vertex : graph->getVertexSet()) {
        for (Edge<Node> *edge : vertex->getOutgoing()) {
            gv->addEdge(id, gv->getNode(vertex->getInfo().getNodeId()), gv->getNode(edge->getDest()->getInfo().getNodeId()), Ed::EdgeType::DIRECTED);
            id++;
        }
    }
}

void GUI::show() {
    gv->createWindow();
    gv->join();
}

GUI::~GUI() {
    if (gv != nullptr) {
        if (gv->isWindowOpen()) gv->closeWindow();
        delete(gv);
    }
}
