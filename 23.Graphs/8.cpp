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

    bool isBipartite(){
       
        vector<int> color(V,-1);
        queue<int>q;

        color[0]=0;
        q.push(0);

        while(q.size()>0){
            int curr=q.front();
            q.pop();
            for(int i:l[curr]){
                if(color[i]==-1){
                    
                    color[i]=!color[curr];
                    q.push(i);
                }
                else{
                    if(color[i]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

   
   
};
int main(){
    Graph g(5);
    g.addedge(1,0);
    g.addedge(0,2);
    g.addedge(2,4);
    g.addedge(3,4);
    g.addedge(3,1);
    cout<<g.isBipartite();

}