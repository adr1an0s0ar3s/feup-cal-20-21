# --------------------------------------------------------------------
# DISCLAIMER: It has to be used with full nodes and strong edges files
# --------------------------------------------------------------------

# Getting used Nodes

edges = open("edges.txt", "r")

distinct_nodes = set()
lines = []

edges.readline()
for line in edges:
    temp = line.replace("(", " ")
    temp = temp.replace(",", " ")
    temp = temp.replace(")", " ")
    edge = temp.split()
    edge[0], edge[1] = int(edge[0]), int(edge[1])
    lines.append(edge)
    distinct_nodes.add(edge[0])
    distinct_nodes.add(edge[1])

sorted_nodes = list(distinct_nodes)
sorted_nodes.sort()
edges.close()

# Changing nodes in edge

edges = open("edges.txt", "w")

edges.write(f"{len(lines)}\n")
for line in lines:
    edges.write(f"({sorted_nodes.index(line[0])+1},{sorted_nodes.index(line[1])+1})\n")

edges.close()
lines.clear()

# Changing nodes in nodes

nodes = open("nodes_xy.txt", "r")

nodes.readline()

for line in nodes:
    temp = line.replace("(", " ")
    temp = temp.replace(",", " ")
    temp = temp.replace(")", " ")
    node = temp.split()
    node[0] = int(node[0])
    try:
        sorted_nodes.index(node[0])
    except ValueError:
        continue
    lines.append(node)

nodes.close()

nodes = open("nodes_xy.txt", "w")

nodes.write(f"{len(lines)}\n")

for i, line in enumerate(lines):
    nodes.write(f"({i+1},{line[1]},{line[2]})\n")

nodes.close()