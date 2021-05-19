#include "GUI.h"

using Nd = GraphViewer::Node;
using Ed = GraphViewer::Edge;

GUI::GUI(const Graph<Node> * graph, int width, int height): graph(graph), width(width), height(height), gv(new GraphViewer()) {}

void GUI::show() {

    gv->setCenter(sf::Vector2f(width/2,height/2));

    for (Vertex<Node> *vertex: graph->getVertexSet()) {
        // Add node
        Nd &node = gv->addNode(vertex->getInfo().getNodeId(), sf::Vector2f(vertex->getInfo().getX(), vertex->getInfo().getY()));

        if (vertex->getInfo().getClient() != nullptr) {         // If a vertex is a Client
            node.setLabel(vertex->getInfo().getClient()->getName());
            node.setSize(15);
            node.setColor(sf::Color::Red);
        } else if (vertex->getInfo().getSupplier() != nullptr) {  // If a vertex is a Supplier
            node.setLabel("Supplier");
            node.setSize(15);
            node.setColor(sf::Color::Green);
        } else {
            node.setSize(5);
        }
    }

    int id = 0;
    for (Vertex<Node> *vertex : graph->getVertexSet()) {
        for (Edge<Node> *edge : vertex->getOutgoing()) {
            gv->addEdge(id, gv->getNode(vertex->getInfo().getNodeId()), gv->getNode(edge->getDest()->getInfo().getNodeId()), Ed::EdgeType::DIRECTED);
            id++;
        }
    }

    gv->setEnabledNodes(false);
    createGV();
}

void GUI::deleteGV() {
    if (gv != nullptr) {
        gv->closeWindow();
        delete(gv);
    }
}

void GUI::createGV() {
    gv->createWindow();
    gv->join();
}

void GUI::closeGV() {
    cout << "Press Enter to exit graph viewer." << endl;
    if (getchar() == '\n') deleteGV();
    else cin.ignore(1000, '\n');
}
