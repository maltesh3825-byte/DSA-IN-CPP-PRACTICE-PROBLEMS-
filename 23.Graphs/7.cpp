//cycle detection for undirected graph
#include<iostream>
#include<list>
#include<vector>
#include<queue>
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
    bool undirCycleHelper(int src,int par,vector<bool> &vis){
        vis[src]=true;
        list<int> neighbours=l[src];
        for(int v:neighbours){
            if(!vis[v]){
                if(undirCycleHelper(v,src,vis)){
                    return true;
                }
            }
            else{
                if(v!=par){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycleUndir(){
        vector<bool> vis(7,false);
       return undirCycleHelper(0,-1,vis);
    }
};
int main(){
    Graph g(10);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(0,3);
    g.addedge(1,2);
    g.addedge(3,4);
    cout<<g.isCycleUndir();

}