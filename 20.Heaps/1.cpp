 #include<iostream>
 #include<queue>
 using namespace std;
 int main(){
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> p;
    pq.push(5);
    pq.push(10);
    pq.push(7);
    pq.push(4);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    
    p.push(5);
    p.push(10);
    p.push(7);
    p.push(4);
    
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    return 0;
 }
