# Simple Prim's Algorithm Example
# College Campus Graph - Minimum Spanning Tree (MST)

# Departments (Nodes)
nodes = ["CS", "EE", "ME", "Library"]

# Connections (Edges: from, to, distance)
edges = [
    ("CS", "EE", 10),
    ("CS", "ME", 6),
    ("CS", "Library", 5),
    ("EE", "Library", 15),
    ("ME", "Library", 4)
]

# Build adjacency map for easy lookups
adj = {n: [] for n in nodes}
for u, v, w in edges:
    adj[u].append((v, w))
    adj[v].append((u, w))

# Prim's algorithm (simple, no heap)
start = nodes[0]          # start from the first node (CS)
visited = {start}         # set of nodes already in MST
mst = []                  # list of edges in MST
total_weight = 0

# Repeat until all nodes are visited
while len(visited) < len(nodes):
    # find the smallest edge that connects visited -> not visited
    best_edge = None  # will hold (u, v, w)
    best_w = float('inf')

    for u in visited:
        for v, w in adj[u]:
            if v not in visited and w < best_w:
                best_w = w
                best_edge = (u, v, w)

    if best_edge is None:
        # graph not fully connected
        break

    u, v, w = best_edge
    visited.add(v)
    mst.append((u, v, w))
    total_weight += w

# Print result
print("Edges in Minimum Spanning Tree (Prim):")
for u, v, w in mst:
    print(f"{u} -- {v} : {w}")
print("Total Distance =", total_weight)
