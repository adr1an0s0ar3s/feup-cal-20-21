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
        std::string map = "espinho";
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

public:
    Application();
};

#endif //MARKET_ON_WHEELS_APPLICATION_H
