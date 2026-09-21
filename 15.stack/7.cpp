//stock span code
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void stocks(vector<int> &stock,vector<int> & span){
    stack<int> s;
    s.push(0);
    span[0]=1;
    for(int i=0;i<stock.size();i++){
        int curr=stock[i];
        while(!s.empty()&&curr>=stock[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span[i]=i+1;
        }
        else{
            int prehigh=s.top();
            span[i]=i-prehigh;
        }
        s.push(i);

    }
    for(int i =0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    vector <int> stock={100,80,60,70,60,85,100};
    vector <int> span={0,0,0,0,0,0,0};
    stocks(stock,span);
    return 0;
}

