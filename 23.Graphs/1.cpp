//creating a graph using adjacency list 
#include<iostream>
#include<list>
#include<vector>
using  namespace std;
class Graph{
int V;
list<int>*l;
public:
    Graph(int V){
        this->V=V;
        l = new list<int> [V];
    }

    void addedge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u=0;u<V;u++){
            list<int> neighbours= l[u];
            cout<<u<<" : ";
            for(int v:neighbours){
                cout<<v<<" ";
            }
            cout<<"\n";

            
        }
    }
};
int main(){
    Graph g(5);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.addedge(2,4);
    g.print();

}