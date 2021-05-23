#ifndef MARKET_ON_WHEELS_APPLICATION_H
#define MARKET_ON_WHEELS_APPLICATION_H

#include "graph/Graph.h"
#include "graph/Node.h"

#include "market/Client.h"
#include "market/Order.h"
#include "market/Product.h"
#include "market/Supplier.h"
#include "market/Vehicle.h"

#include <vector>

class Application {
private:
    Graph<Node> graph;
    int centerID;

    std::vector<Client> clients;
    std::vector<Order> orders;
    std::vector<Product> products;
    std::vector<Supplier> suppliers;
    std::vector<Vehicle> vehicles;

    struct IOFiles {
        const std::string nodesFile = "nodes_xy.txt";
        const std::string edgesFile = "edges.txt";
        const std::string clientsFile = "clients.txt";
        const std::string ordersFile = "orders.txt";
        const std::string productsFile = "products.txt";
        const std::string suppliersFile = "suppliers.txt";
        const std::string vehiclesFile = "vehicles.txt";
        std::string map = "espinho_strong";
    };

    IOFiles files;

    bool loadNodes();

    bool loadEdges();

    bool loadClients();

    bool loadOrders();

    bool loadProducts();

    bool loadSuppliers();

    bool loadVehicles();

    bool loadData();

    std::vector<Order> filterOrders() const;

    double getTotalWeight(const Order &order) const;

public:
    Application();

    const Graph<Node> & getGraph() const;

    int getCenterId() const;

    bool setCenterId(int centerID);

    void setMap(const std::string &map);

    std::vector<Path> shortestPath();
};

#endif //MARKET_ON_WHEELS_APPLICATION_H
