# Simple Kruskal's Algorithm Example
# College Campus Graph - Minimum Spanning Tree (MST)

# Departments (Nodes)
nodes = ["CS", "EE", "ME", "Library"]

# Connections between them (Edges: from, to, distance)
edges = [
    ("CS", "EE", 10),
    ("CS", "ME", 6),
    ("CS", "Library", 5),
    ("EE", "Library", 15),
    ("ME", "Library", 4)
]

# Step 1: Sort all edges by distance (smallest first)
edges.sort(key=lambda x: x[2])

# Step 2: Create a parent dictionary for union-find
parent = {}
for n in nodes:
    parent[n] = n

# Function to find root of a node
def find(node):
    while parent[node] != node:
        node = parent[node]
    return node

# Function to join two sets
def union(node1, node2):
    root1 = find(node1)
    root2 = find(node2)
    parent[root2] = root1

# Step 3: Kruskal’s Algorithm
mst = []   # to store final MST edges
total_weight = 0

for u, v, w in edges:
    # If including this edge doesn’t cause a cycle
    if find(u) != find(v):
        union(u, v)
        mst.append((u, v, w))
        total_weight += w

# Step 4: Print result
print("Edges in Minimum Spanning Tree:")
for u, v, w in mst:
    print(f"{u} -- {v} : {w}")

print("Total Distance =", total_weight)
