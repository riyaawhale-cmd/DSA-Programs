class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.adj_list = [[] for _ in range(vertices)]
        self.edges = []

    def add_edge(self, u, v, weight):
        if 0 <= u < self.V and 0 <= v < self.V:
            self.adj_list[u].append((v, weight))
            self.adj_list[v].append((u, weight))
            self.edges.append((weight, u, v))

    def display_list(self):
        print("\n--- Weighted Adjacency List ---")
        for i in range(self.V):
            neighbors = " -> ".join(f"{v}(w:{w})" for v, w in self.adj_list[i])
            print(f"{i}: {neighbors}")

    def find(self, parent, i):
        if parent[i] != i:
            parent[i] = self.find(parent, parent[i])
        return parent[i]

    def union(self, parent, rank, x, y):
        root_x = self.find(parent, x)
        root_y = self.find(parent, y)

        if rank[root_x] < rank[root_y]:
            parent[root_x] = root_y
        elif rank[root_x] > rank[root_y]:
            parent[root_y] = root_x
        else:
            parent[root_y] = root_x
            rank[root_x] += 1

    def kruskal_mst(self):
        # Sort all edges in ascending order of weight
        self.edges.sort()

        parent = [i for i in range(self.V)]
        rank = [0] * self.V

        mst = []
        total_cost = 0

        for weight, u, v in self.edges:
            root_u = self.find(parent, u)
            root_v = self.find(parent, v)

            # Include edge if it does not form a cycle
            if root_u != root_v:
                mst.append((u, v, weight))
                total_cost += weight
                self.union(parent, rank, root_u, root_v)

        print("\n--- Minimum Spanning Tree (Kruskal's) ---")
        for u, v, weight in mst:
            print(f"{u} -- {v}  ==  {weight}")
        print(f"Total Minimum Cost: {total_cost}")


if __name__ == "__main__":
    v = int(input("Enter number of vertices: "))
    e = int(input("Enter number of edges: "))

    g = Graph(v)

    print("Enter edges (u v weight) using 0-based indexing:")
    for _ in range(e):
        u, w, weight = map(int, input().split())
        g.add_edge(u, w, weight)

    g.display_list()
    g.kruskal_mst()