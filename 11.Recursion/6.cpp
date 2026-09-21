//last occurance using recursion
#include<iostream>
#include<vector>

using namespace std;
int lastOcc(vector<int> arr,int i,int target){
   if(i==arr.size()){
    return -1;
   }
   int idxfound=lastOcc(arr,i+1,target);
   if(arr[i]==target&&idxfound==-1){
    return i;
   }
   return idxfound;
}
int main(){
    vector<int> arr={1,2,3,4,3,5,8,9,8};
    cout<<lastOcc(arr,0,3);
    return 0;
}