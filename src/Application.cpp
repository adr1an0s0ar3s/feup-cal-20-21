#include "Application.h"
#include "util/Utils.h"

#include <fstream>
#include <sstream>

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
        // TODO: NOT WORKING graph.addVertex(n);
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
        // TODO: NOT WORKING graph.addEdge(n1, n2, weight);
    }

    file.close();
    return true;
}

bool Application::loadClients() {
    std::string line;
    int clientId, nodeId;

    std::ifstream file("../maps/" + files.map + "/" + files.clientsFile);
    if (!file.is_open()) return false;

    getline(file, line);
    int nClients = stoi(line);
    // TODO: NOT WORKING clients = std::vector<Client>(nClients);
    for (int i = 0; i < nClients; ++i) {
        getline(file, line, '(');
        getline(file, line, ',');
        clientId = stoi(line);

        getline(file, line, ',');
        nodeId = stoi(line);

        getline(file, line, ')');
        clients[i] = Client(clientId, nodeId, line);
        // TODO: atualizar node com este client
    }

    file.close();
    return true;
}

bool Application::loadOrders() {
    std::string line;
    int orderId, clientId, productId, quantity;

    std::ifstream file("../maps/" + files.map + "/" + files.ordersFile);
    if (!file.is_open()) return false;

    getline(file, line);
    int nOrders = stoi(line);
    // TODO: NOT WORKING orders = std::vector<Order>(nOrders);
    for (int i = 0; i < nOrders; ++i) {
        getline(file, line, '(');
        getline(file, line, ',');
        orderId = stoi(line);

        getline(file, line, ',');
        clientId = stoi(line);

        getline(file, line, ')');

        Order o(orderId, &(clients[clientId - 1]));
        orders[i] = o;

        stringstream ss(line);
        while (getline(ss, line, ',')) {
            stringstream ss2(line);
            ss2 >> productId >> quantity;
            orders[i].getProducts().setQuantity(productId, quantity);
        }
    }

    file.close();
    return true;
}

bool Application::loadProducts() {
    return false;
}

bool Application::loadSuppliers() {
    return false;
}

bool Application::loadVehicles() {
    std::string line;
    int vehicleId;
    double capacity;

    std::ifstream file("../maps/" + files.map + "/" + files.vehiclesFile);
    if (!file.is_open()) return false;

    getline(file, line);
    int nVehicles = stoi(line);
    // TODO: NOT WORKING vehicles = std::vector<Vehicle>(nVehicles);
    for (int i = 0; i < nVehicles; ++i) {
        getline(file, line, '(');
        getline(file, line, ',');
        vehicleId = stoi(line);

        getline(file, line, ',');
        capacity = stod(line);

        vehicles[i] = Vehicle(vehicleId, capacity);
    }

    file.close();
    return true;
}

bool Application::loadData() {
    if (!loadNodes()) {
        std::cout << "Failed to load nodes\n";
        return false;
    }
    if (!loadEdges()) {
        std::cout << "Failed to load edges\n";
        return false;
    }
    if (!loadOrders()) {
        std::cout << "Failed to load orders\n";
        return false;
    }

    if (!loadVehicles()) {
        std::cout << "Failed to load vehicles\n";
        return false;
    }
    return true;
}

void Application::setMap(const string &map) {
    files.map = map;
};