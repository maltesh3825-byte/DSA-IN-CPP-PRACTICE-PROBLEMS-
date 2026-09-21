//traversal for disconnected graphs by dfs and bfs
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
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dsfhelper(i,vis);
                cout<<endl;
            }
        }
    }
    void bsfhelper(int st,vector<bool> &vis){
        
        queue<int>q;
        q.push(st);
        vis[st]=true;
        
        while(q.size()>0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            list<int> neighbours=l[u];

            for(int v :neighbours){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
       
    }
    void bsf(){
        vector<bool> vis(7,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bsfhelper(i,vis);
                cout<<endl;
            }
        }
    }
};
int main(){
    Graph g(10);
    g.addedge(0,2);
    g.addedge(2,5);
    g.addedge(1,6);
    g.addedge(6,4);
    g.addedge(4,3);
    g.addedge(4,9);
    g.addedge(3,7);
    g.addedge(3,8);
    g.bsf();cout<<endl;
    g.dsf();

}