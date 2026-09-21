//topological sorting using dfs
#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<stack>
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
    void topoHelper(int src,vector<bool> & vis,stack<int> & s){
        vis[src]=true;
        for(auto v : l[src]){
            if(!vis[v]){
                topoHelper(v,vis,s);
            }
        }
        s.push(src);
    }

    void topoSort(){
        vector <bool> vis(7,false);
        stack <int> s;
        for(int i=0;i<V;i++){
            topoHelper(i,vis,s);
        }
        while(s.size()>0){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<"\n";
    }
   
   
};
int main(){
    Graph g(6,false);
    g.addedge(5,0);
    g.addedge(4,0);
    g.addedge(5,2);
    g.addedge(2,3);
    g.addedge(3,1);
    g.addedge(4,1);
    g.topoSort();

}