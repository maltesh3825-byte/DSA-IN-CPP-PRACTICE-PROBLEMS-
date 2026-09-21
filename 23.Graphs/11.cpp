//topological sorting using kahn's  algorithm
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
    void calIndegree(vector<int> &indeg){
        for(int i=0;i<V;i++){
            list<int> neighbors=l[i];
            for(int i:  neighbors){
                indeg[i]++;
            }
        }
    }

    void topoSort2(){//kahn's algorithm
        vector<int> indeg(V,0);
        calIndegree(indeg);
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(q.size()>0){
            int curr= q.front();
            q.pop();
            cout<<curr<<" ";
            for(int i:l[curr]){
                indeg[i]--;
                if(indeg[i]==0){
                    q.push(i);
                }
            }
        }
        cout<<endl;


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
    g.topoSort2();

}