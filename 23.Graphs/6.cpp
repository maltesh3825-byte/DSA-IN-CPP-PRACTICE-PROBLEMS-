//cycle detection for directed graph
#include<iostream>
#include<list>
#include<vector>
#include<queue>
using  namespace std;
    class Graph{
    int V;
    bool isUndir;
    list<int>*l;
public:
    Graph(int V,bool isUndir=true){
        this->V=V;
        l = new list<int> [V];
        this->isUndir=isUndir;
    }

    void addedge(int u,int v){
        l[u].push_back(v);
        if(isUndir){ 
             l[v].push_back(u);
        }
    }


   
    
    bool dirCycleHelper(int src,vector<bool> &vis,vector<bool>& recPath){
        vis[src]=true;
        recPath[src]=true;
        list<int> neighbours=l[src];
        for(int v:neighbours){
            if(!vis[v]){
                if(dirCycleHelper(v,vis,recPath)){
                    return true;
                }
            }
            else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }
    bool isCycledir(){
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dirCycleHelper(i,vis,recPath)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Graph g(4,false);
    g.addedge(1,0);
    g.addedge(0,2);
    g.addedge(2,3);
    g.addedge(3,0);
    cout<<g.isCycledir();

}