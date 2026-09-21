//connect n ropes
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void connectRopes(vector<int> l){
    priority_queue<int, vector<int>, greater<int>> pq(l.begin(),l.end());
    int sum=0;
    while(pq.size()>1){
        int min1=pq.top();
        pq.pop();
        int min2=pq.top();
        pq.pop();
        sum+=min1+min2;
        pq.push(min1+min2);
        

    }
    cout<<"min cost : "<<sum<<endl;
}
int main(){
    vector<int> l={4,3,2,6};
    connectRopes(l);
    return 0;
}