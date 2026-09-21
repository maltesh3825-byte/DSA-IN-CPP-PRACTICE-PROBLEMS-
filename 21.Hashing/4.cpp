//pair sum O(n)
#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,int> m;
    int arr[]={1,2,7,11,15,5,9};
    int target=9;
    for(int i=0;i<7;i++){
        int cum=target-arr[i];
        if(m.count(cum)){
            cout<<"ans = "<<m[cum]<<","<<i<<endl;
        }
        m[arr[i]]=i;

    }

    return 0;
}
