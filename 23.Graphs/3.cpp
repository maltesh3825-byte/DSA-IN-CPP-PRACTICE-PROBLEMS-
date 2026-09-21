//dsf
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
    void dsfhelper(int u,vector<bool> &vis){
        vis[u]=true;
        cout<<u<<" ";
        for(auto v:l[u]){
            if(!vis[v]){
                dsfhelper(v,vis);
            }
           
        }
    }
    void dsf(){
        vector<bool> vis(7,false);
        dsfhelper(0,vis);
    }
};
int main(){
   Graph g(7);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(2,4);
    g.addedge(3,4);
    g.addedge(5,6);
    g.addedge(3,5);
    g.addedge(4,5);
    g.dsf();
}