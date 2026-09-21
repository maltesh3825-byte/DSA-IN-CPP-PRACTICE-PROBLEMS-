//find the next greatest integer
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void greatestInt(vector<int> & arr,vector<int> ans){
    stack<int> s;
    int idx=arr.size()-1;
    s.push(arr[idx]);
    ans[idx]=-1;
    for(idx=idx-1;idx>=0;idx--){
        while(!s.empty() && arr[idx]>=s.top() ){
            s.pop();
        }
        if(s.empty()){
            ans[idx]= -1;
            s.push(arr[idx]);
        }
        else{
            int nxtg=s.top();
            ans[idx]=nxtg;
        }
        s.push(arr[idx]);

        
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    vector<int> arr={6,8,0,1,3};
    vector<int> ans={0,0,0,0,0};
    greatestInt(arr,ans);
    return 0;
}