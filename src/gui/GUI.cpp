#include "GUI.h"

using Nd = GraphViewer::Node;
using Ed = GraphViewer::Edge;

GUI::GUI(const Graph<Node> * graph, int width, int height): graph(graph), width(width), height(height), gv(new GraphViewer()) {

    for (Vertex<Node> *vertex: graph->getVertexSet()) {

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

    for (Vertex<Node> *vertex : graph->getVertexSet())
        for (Edge<Node> *edge : vertex->getOutgoing())
            gv->addEdge(edge->getId(), gv->getNode(vertex->getInfo().getNodeId()),gv->getNode(edge->getDest()->getInfo().getNodeId()), Ed::EdgeType::DIRECTED);
}

void GUI::show(int centerId) {
    // Draw center node
    Nd &node = gv->getNode(centerId);
    node.setLabel("Center");
    node.setSize(100);
    node.setColor(sf::Color::Cyan);

    // Center on center node
    gv->setCenter(node.getPosition());

    gv->createWindow(width, height);
    gv->join();
    gv->closeWindow();

    // Remove center node
    node.setLabel("");
    node.setSize(0);
    node.setColor(sf::Color::Black);
}

void GUI::showPaths(int centerId, const std::vector<Path> &paths) {
    sf::Color colors[] = {sf::Color::Cyan, sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Magenta, sf::Color::Yellow};
    int color = 0;
    for (const Path &path: paths) {
        for (int id: path.getPath()) gv->getEdge(id).setColor(colors[color]);
        color = (color + 1) % 6;
    }
    show(centerId);
    for (const Path &path: paths) for (int id: path.getPath()) gv->getEdge(id).setColor(sf::Color::Black);
}

GUI::~GUI() {
    if (gv != nullptr) {
        if (gv->isWindowOpen()) gv->closeWindow();
        delete(gv);
    }
}
