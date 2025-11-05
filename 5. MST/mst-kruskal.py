# kruskal_from_adjacency.py
# Simple Kruskal's algorithm that starts from an adjacency list (undirected graph).

# --- 1) Define graph as adjacency list: node -> [(neighbor, distance), ...]
graph = {
    "CS":      [("EE", 10), ("ME", 6), ("Library", 5)],
    "EE":      [("CS", 10), ("Library", 15)],
    "ME":      [("CS", 6),  ("Library", 4)],
    "Library": [("CS", 5),  ("EE", 15), ("ME", 4)]
}

# --- 2) Convert adjacency list to an edge list (avoid duplicate edges)
edges = []
seen = set()
for u, nbrs in graph.items():
    for v, w in nbrs:
        key = tuple(sorted((u, v)))
        if key not in seen:
            edges.append((u, v, w))
            seen.add(key)

# --- 3) Sort edges by weight (smallest first)
edges.sort(key=lambda x: x[2])

# --- 4) Simple union-find (parent dict) like your example
parent = {}
for n in graph.keys():
    parent[n] = n

def find(node):
    # simple find (no recursion, no path compression) to match your style
    while parent[node] != node:
        node = parent[node]
    return node

def union(a, b):
    root_a = find(a)
    root_b = find(b)
    parent[root_b] = root_a

# --- 5) Kruskal's algorithm
mst = []
total_weight = 0

for u, v, w in edges:
    if find(u) != find(v):
        union(u, v)
        mst.append((u, v, w))
        total_weight += w

# --- 6) Print result
print("Edges in Minimum Spanning Tree:")
for u, v, w in mst:
    print(f"{u} -- {v} : {w}")

print("Total Distance =", total_weight)
