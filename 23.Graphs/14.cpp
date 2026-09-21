//MST using prim's algorithm
#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Graph{
    int V;
    list<pair<int, int>> * l;
    bool isUndir;
public:
    Graph(int V, bool isUndir=true ){
        this->V=V;
        this->isUndir= isUndir;
        l= new list<pair<int,int>>[V];
    }
    void addedge(int u, int v, int wt){
        l[u].push_back(make_pair(v,wt));
        if(isUndir){
            l[v].push_back(make_pair(u,wt));
        }
    }

    void primsAlgo(int src){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0,src));//src to src wt is 0 hence 0, src where 0 is the weight
        
        vector<bool>mst(7,false);
        int ans=0;
        while(pq.size()>0){
            int u= pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            if(!mst[u]){
                mst[u]= true;
                ans+=wt;
                for(auto i : l[u]){
                    int v = i.first;
                    int currWt = i.second;
                    pq.push(make_pair(currWt, v));
                }
            }
        }
        cout<<"final cost of MST = "<<ans<<endl;
        
    }
};
int main(){
    Graph g(5); 
    g.addedge(0,1,10);
    g.addedge(0,2,15);
    g.addedge(0,3,30);
    g.addedge(2,3,50);
    g.addedge(3,1,40);

    g.primsAlgo(0);

}