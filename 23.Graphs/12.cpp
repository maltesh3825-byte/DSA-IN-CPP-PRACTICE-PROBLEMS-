//dijkstra's algorithm
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
void dijkstra(int src,vector<vector<Edge>> &graph, int v){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,  int>>> pq;
    vector<int> dist(v,INT_MAX);
    pq.push(make_pair(0,src));
    dist[src]=0;

    while(pq.size()>0){
        int u= pq.top().second;
        pq.pop();
        vector<Edge>edges =graph[u];
        for(Edge e : edges){
            if(dist[e.v]>dist[u]+e.wt){
                dist[e.v]= dist[u]+e.wt;
                pq.push(make_pair(dist[e.v],e.v));
            }
        }
    }
    for(int u : dist){
        cout<< u << " ";
    }
    cout<<endl;
}
int main(){
    int V = 6;
    vector<vector<Edge>> graph(V);

    // Graph initialization (matching video snippet)
    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));

    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(2, 5));

    // Run Dijkstra starting from source vertex 0
    dijkstra(0, graph, V);

    return 0;
}