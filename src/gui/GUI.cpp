#include "GUI.h"

using Nd = GraphViewer::Node;
//using Edge = GraphViewer::Edge;

void GUI::show() {
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
}

void GUI::deleteGV() {
    if (gv != nullptr) {
        gv->closeWindow();
        delete(gv);
    }
}

void GUI::createGV() {
    this->gv = new GraphViewer();
    gv->createWindow(width, height);
    gv->join();
}

void GUI::closeGV() {
    cout << "Press Enter to exit graph viewer." << endl;
    if (getchar() == '\n') deleteGV();
    else cin.ignore(1000, '\n');
}
