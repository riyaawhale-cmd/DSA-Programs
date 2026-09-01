#include <iostream>
using namespace std;

class Graph
{
    int adj[20][20];
    int n;
    bool visited[20];

public:
    Graph()
    {
        n = 0;

        for (int i = 0; i < 20; i++)
        {
            visited[i] = false;

            for (int j = 0; j < 20; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void createGraph()
    {
        cout << "Enter number of vertices: ";
        cin >> n;

        // Initialize adjacency matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }
        }

        int edges;
        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "Enter edges (source destination):\n";

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u][v] = 1;
            adj[v][u] = 1;   // For undirected graph
        }
    }

    void displayMatrix()
    {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void resetVisited()
    {
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
    }

    void DFS(int start)
    {
        visited[start] = true;

        cout << start << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[start][i] == 1 && !visited[i])
            {
                DFS(i);
            }
        }
    }
};

int main()
{
    Graph g;
    int choice, start;

    do
    {
        cout << "\n===== Graph Menu =====";
        cout << "\n1. Create a Graph";
        cout << "\n2. Display Graph (Adjacency Matrix)";
        cout << "\n3. DFS Traversal";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.createGraph();
            break;

        case 2:
            g.displayMatrix();
            break;

        case 3:
            g.resetVisited();

            cout << "\nEnter starting vertex: ";
            cin >> start;

            if (start >= 0 && start < 20)
            {
                cout << "DFS Traversal: ";
                g.DFS(start);
                cout << endl;
            }
            else
            {
                cout << "Invalid starting vertex!";
            }
            break;

        case 4:
            cout << "Program Exited.";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 4);

    return 0;
}