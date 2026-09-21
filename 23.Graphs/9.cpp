//all paths problem (solved in lc(797) with diff approach, the below is the mam's approach with O(V+E))
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class Graph {
    int V;
    list<int>* l;
    bool isDirected;

public:
    Graph(int v, bool directed = true) {
        V = v;
        l = new list<int>[V];
        isDirected = directed;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        if (!isDirected) {
            l[v].push_back(u);
        }
    }

    void pathHelper(int src, int dest, vector<bool>& vis, string path) {
        if (src == dest) {
            cout << path << dest << endl;
            return;
        }

        vis[src] = true;
        path += to_string(src);
        list<int> neighbors = l[src];

        for (int v : neighbors) {
            if (!vis[v]) {
                pathHelper(v, dest, vis, path);
            }
        }

        vis[src] = false; // Backtracking step
    }

    void printAllPaths(int src, int dest) {
        vector<bool> vis(V, false);
        string path = "";
        pathHelper(src, dest, vis, path);
    }
};

int main() {
    Graph graph(6);
    
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);
    graph.printAllPaths(5,1);
    // Call printAllPaths to display paths between desired nodes
    // e.g., graph.printAllPaths(5, 1);

    return 0;
} 