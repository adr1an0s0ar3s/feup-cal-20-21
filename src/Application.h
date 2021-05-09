#ifndef MARKET_ON_WHEELS_APPLICATION_H
#define MARKET_ON_WHEELS_APPLICATION_H

#include "graph/Graph.h"
// #include "graph/Node.h"

// #include "graphviewer/GraphViewer.h"

#include "market/Client.h"
#include "market/Order.h"
#include "market/Product.h"
#include "market/Supplier.h"
#include "market/Vehicle.h"

#include <vector>

class Application {
private:
    // Graph<Node> graph;

    std::vector<Client> clients;
    std::vector<Order> orders;
    std::vector<Product> products;
    std::vector<Supplier> suppliers;
    std::vector<Vehicle> vehicles;

    // GraphViewer gv;

    struct IOFiles {
        const std::string nodesFile = "";
        const std::string edgesFile = "";
        const std::string clientsFile = "";
        const std::string ordersFile = "";
        const std::string productsFile = "";
        const std::string suppliersFile = "";
        const std::string vehiclesFile = "";
    };

    bool loadNodes();

    bool loadEdges();

    bool loadClients();

    bool loadOrders();

    bool loadProducts();

    bool loadSuppliers();

    bool loadVehicles();

public:
    Application();

    bool loadData();
};

#endif //MARKET_ON_WHEELS_APPLICATION_H
