//pq for pairs
#include<iostream>
#include<queue>
using namespace std;
struct Compare_pair{
    bool operator () (pair<string,int> &p1,pair<string,int> &p2){
        return p1.first > p2.first;
    }
};
int main(){
    priority_queue <pair<string,int>,vector<pair<string,int>>,Compare_pair> pq;
    pq.push(make_pair("ajay",78));
    pq.push(make_pair("lisa",99));
    pq.push(make_pair("kia",47));
    
    
    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }

    return 0;
}
