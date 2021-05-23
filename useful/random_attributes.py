import random

usedNodes = set()

# Randomizing Clients

print("Number of clients: ", end="")
nClients = int(input())
print("Number of suppliers: ", end="")
nSuppliers = int(input())
print("Number of nodes: ", end="")
nNodes = int(input())

if (nClients + nSuppliers + 1 > nNodes):
    print("nClients + nSuppliers + 1 > nNodes")
    exit()

output = open("clients.txt", "w")
names = open("names/client_names.txt", "r")

output.write(f"{nClients}\n")

for i in range(nClients):
    while True:
        node = random.randint(1, nNodes)
        if node not in usedNodes:
            usedNodes.add(node)
            break
    output.write(f"({i+1},{node},{names.readline().split()[0]})\n")

output.close()
names.close()

# Randomizing Products

print("Number of products: ", end="")
nProducts = int(input())
print("Maximum weight of product: ", end="")
maxWeight = int(input())

output = open("products.txt", "w")
names = open("names/product_names.txt", "r")

output.write(f"{nProducts}\n")

for i in range(nProducts):
    output.write(f"({i+1},{names.readline().split()[0]},{int(random.randint(1,maxWeight)/random.randint(1,10)*10)/10},{int(random.randint(1,10)/random.randint(1,10)*10)/10})\n")

output.close()
names.close()

# Randomizing Orders

print("Number of orders: ", end="")
nOrders = int(input())
print("Maximum number of products: ", end="")
maxProducts = int(input())
print("Maximum number of products quantity: ", end="")
maxQuantity = int(input())

usedClients = set()

output = open("orders.txt", "w")

output.write(f"{nOrders}\n")

for i in range(nOrders):
    while True:
        client = random.randint(1, nClients)
        if client not in usedClients:
            usedClients.add(client)
            break
        elif len(usedClients) == nClients:
            break
    output.write(f"({i+1},{client}")
    for j in range(random.randint(1, maxProducts)):
        quantity = random.randint(1, maxQuantity)
        product = random.randint(1, nProducts)
        output.write(f",{product} {quantity}")
    output.write(")\n")

output.close()

# Randomizing Suppliers

output = open("suppliers.txt", "w")

output.write(f"{nSuppliers}\n")

for i in range(nSuppliers):
    while True:
        node = random.randint(1, nNodes)
        if node not in usedNodes:
            usedNodes.add(node)
            break
    output.write(f"({i+1},{node}")
    products = set()
    for j in range(random.randint(1, nProducts)):
        while True:
            product = random.randint(1, nProducts)
            if product not in products:
                products.add(product)
                break;
        quantity = random.randint(1, 10)
        output.write(f",{product} {quantity}")
    output.write(")\n")

output.close()

# Create vehicles

print("Number of vehicles: ", end="")
nVehicles = int(input())
print("Maximum capacity: ", end="")
maxCapacity = int(input())

output = open("vehicles.txt", "w")

output.write(f"{nVehicles}\n")

for i in range(nVehicles):
    output.write(f"({i+1},{random.randint(1, maxCapacity)})\n")

output.close()