#include "GUI.h"

using Nd = GraphViewer::Node;
using Ed = GraphViewer::Edge;

GUI::GUI(const Graph<Node> * graph, int centerID, int width, int height): graph(graph), centerID(centerID), width(width), height(height), gv(new GraphViewer()) {

    for (Vertex<Node> *vertex: graph->getVertexSet()) {

        Nd &node = gv->addNode(vertex->getInfo().getNodeId(), sf::Vector2f(vertex->getInfo().getX(), vertex->getInfo().getY()));

        if (vertex->getInfo().getClient() != nullptr) {         // If a vertex is a Client
            node.setLabel(vertex->getInfo().getClient()->getName());
            node.setSize(50);
            node.setColor(sf::Color::Red);
        } else if (vertex->getInfo().getSupplier() != nullptr) {  // If a vertex is a Supplier
            node.setLabel("Supplier");
            node.setSize(50);
            node.setColor(sf::Color::Green);
        } else if (vertex->getInfo().getNodeId() == centerID) {
            node.setLabel("Center");
            node.setSize(50);
            node.setColor(sf::Color::Cyan);
        } else node.setSize(0);
    }

    for (Vertex<Node> *vertex : graph->getVertexSet()) {
        for (Edge<Node> *edge : vertex->getOutgoing())
            gv->addEdge(edge->getId(), gv->getNode(vertex->getInfo().getNodeId()),gv->getNode(edge->getDest()->getInfo().getNodeId()), Ed::EdgeType::DIRECTED);
    }
}

bool GUI::setCenterID(int centerID) {
    if (gv->getNodes().size() < centerID) return false;

    // Resetting centerNode
    Nd &node = gv->getNode(this->centerID);
    node.setLabel();
    node.setSize(0);
    node.setColor();

    // Updating centerNode
    this->centerID = centerID;
    node = gv->getNode(this->centerID);
    node.setLabel("Center");
    node.setSize(50);
    node.setColor(sf::Color::Cyan);

    return true;
}

void GUI::show() {
    // Center on center node
    gv->setCenter(gv->getNode(centerID).getPosition());
    gv->createWindow(width, height);
    gv->join();
    gv->closeWindow();
}

void GUI::disableNotStrong() {
    for (Vertex<Node> *vertex: graph->getVertexSet()) {
        if(vertex->getInfo().getNodeId() == centerID) std::cout << "Fuck this also!\n";
        if (!vertex->getStrong()) {
            if(vertex->getInfo().getNodeId() == centerID) std::cout << "Fuck this!\n";
            gv->getNode(vertex->getInfo().getNodeId()).disable();
            for (Edge<Node> *edge: vertex->getOutgoing()) gv->getEdge(edge->getId()).disable();
            for (Edge<Node> *edge: vertex->getIncoming()) gv->getEdge(edge->getId()).disable();
        }
    }
}

void GUI::enableNotStrong() {
    for (Vertex<Node> *vertex: graph->getVertexSet()) {
        if (!vertex->getStrong()) {
            gv->getNode(vertex->getInfo().getNodeId()).enable();
            for (Edge<Node> *edge: vertex->getOutgoing()) gv->getEdge(edge->getId()).enable();
            for (Edge<Node> *edge: vertex->getIncoming()) gv->getEdge(edge->getId()).enable();
        }
    }
}

void GUI::showStrong() {
    disableNotStrong();
    show();
    enableNotStrong();
}

void GUI::showPaths(const std::vector<Path> &paths) {
    sf::Color colors[] = {sf::Color::Cyan, sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Magenta, sf::Color::Yellow};

    gv->setCenter(gv->getNode(centerID).getPosition());
    gv->createWindow(width, height);

    int color = 0;
    for (const Path &path: paths) {
        for (int id: path.getPath()) {
            gv->lock();
            gv->getEdge(id).setColor(colors[color]);
            gv->unlock();
            Sleep(5);
            if (!gv->isWindowOpen()) {
                gv->closeWindow();
                for (const Path &path: paths) for (int id: path.getPath()) gv->getEdge(id).setColor(sf::Color::Black);
                return;
            }
        }
        color = (color + 1) % 6;
    }

    gv->join();
    gv->closeWindow();

    for (const Path &path: paths) for (int id: path.getPath()) gv->getEdge(id).setColor(sf::Color::Black);
}

GUI::~GUI() {
    if (gv != nullptr) {
        if (gv->isWindowOpen()) gv->closeWindow();
        delete(gv);
    }
}
