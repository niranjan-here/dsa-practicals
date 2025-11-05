# prims_from_adjacency.py
# Simple Prim's algorithm that starts from an adjacency list (undirected graph).

# --- 1) Define graph as adjacency list: node -> [(neighbor, distance), ...]
graph = {
    "CS":      [("EE", 10), ("ME", 6), ("Library", 5)],
    "EE":      [("CS", 10), ("Library", 15)],
    "ME":      [("CS", 6),  ("Library", 4)],
    "Library": [("CS", 5),  ("EE", 15), ("ME", 4)]
}

# --- 2) Choose a starting node (any node works, say "CS")
start = "CS"

# --- 3) Keep track of visited nodes
visited = set([start])

# --- 4) List to store edges in MST and total weight
mst = []
total_weight = 0

# --- 5) While MST not complete (i.e., not all nodes visited)
while len(visited) < len(graph):
    min_edge = None
    min_weight = float('inf')

    # Loop through all visited nodes and their neighbors
    for u in visited:
        for v, w in graph[u]:
            # Pick smallest edge that connects to an unvisited node
            if v not in visited and w < min_weight:
                min_weight = w
                min_edge = (u, v, w)

    # Add the chosen edge to MST
    if min_edge:
        u, v, w = min_edge
        mst.append(min_edge)
        total_weight += w
        visited.add(v)

# --- 6) Print result
print("Edges in Minimum Spanning Tree:")
for u, v, w in mst:
    print(f"{u} -- {v} : {w}")

print("Total Distance =", total_weight)
