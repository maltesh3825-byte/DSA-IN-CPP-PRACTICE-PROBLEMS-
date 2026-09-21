//belllman's ford algorithm
#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
class Edge{
public:
    int v;
    int wt;
    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
};
void bellman(int src,vector<vector<Edge>> &graph, int v){
    vector<int> dist(v,INT_MAX);
    dist[src]=0;
    for(int i=0;i<v-1;i++){
        for(int u = 0; u<v;u++){
            for(Edge e : graph[u]){
            if(dist[e.v]>dist[u]+e.wt){
                dist[e.v]= dist[u]+e.wt;
            }
    
        }
    }
}
        
    for(int u : dist){
        cout<< u << " ";
    }
    cout<<endl;
}
int main(){
    int V = 5;
    vector<vector<Edge>> graph(V);

    // Graph initialization (matching video snippet)
    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, -4));

    graph[2].push_back(Edge(3, 2));

    graph[3].push_back(Edge(4, 4));

    graph[4].push_back(Edge(1, -1));

    // Run Dijkstra starting from source vertex 0
    bellman(0, graph, V);

    return 0;
}