#include "Application.h"
#include "util/Utils.h"

#include <fstream>

Application::Application() {

}

bool Application::loadNodes() {
    std::string line;
    int nodeId;
    double x, y;

    std::ifstream file("../maps/" + files.map + "/" + files.nodesFile);
    if (!file.is_open()) return false;

    getline(file, line);
    int nNodes = stoi(line);
    for (int i = 0; i < nNodes; ++i) {
        getline(file, line, '(');
        getline(file, line, ',');
        nodeId = stoi(line);

        getline(file, line, ',');
        x = stod(line);

        getline(file, line, ')');
        y = stod(line);
        Node n = Node(nodeId, x, y);
        graph.addVertex(n);
    }

    file.close();
    return true;
}

bool Application::loadEdges() {
    std::string line;
    int orig, dest;
    double weight;

    std::ifstream file("../maps/" + files.map + "/" + files.edgesFile);
    if (!file.is_open()) return false;

    getline(file, line);
    int nEdges = stoi(line);
    for (int i = 0; i < nEdges; ++i) {
        getline(file, line, '(');
        getline(file, line, ',');
        orig = stoi(line);

        getline(file, line, ')');
        dest = stoi(line);

        Node n1 = graph.getVertex(orig - 1)->getInfo();
        Node n2 = graph.getVertex(dest - 1)->getInfo();
        weight = distance(n1.getX(), n1.getY(), n2.getX(), n2.getY());
        graph.addEdge(n1, n2, weight);
    }

    file.close();
    return true;
}

bool Application::loadClients() {
    return false;
}

bool Application::loadOrders() {
    return false;
}

bool Application::loadProducts() {
    return false;
}

bool Application::loadSuppliers() {
    return false;
}

bool Application::loadVehicles() {
    return false;
}

bool Application::loadData() {
    return false;
};