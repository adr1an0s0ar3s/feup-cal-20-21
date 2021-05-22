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
neededProducts = {}

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
        neededProducts[product] = neededProducts.get(product, 0) + quantity
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
    if i != nSuppliers - 1:
        products = set()
        for j in range(random.randint(1, len(neededProducts))):
            while True:
                product = list(neededProducts)[random.randint(0, len(neededProducts)-1)]
                if product not in products:
                    products.add(product)
                    break
            quantity = random.randint(1, int(neededProducts[product]))
            neededProducts[product] = neededProducts[product] - quantity
            if neededProducts[product] == 0:
                neededProducts.pop(product)
            output.write(f",{product} {quantity}")
    else:
        temp = list(neededProducts)
        for j in range(len(neededProducts)):
            output.write(f",{temp[j]} {neededProducts[temp[j]]}")
    output.write(")\n")

output.close()