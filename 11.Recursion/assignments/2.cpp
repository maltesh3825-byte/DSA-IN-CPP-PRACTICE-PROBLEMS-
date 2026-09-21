//find ing occurance
#include<iostream>
using namespace std;
void FindOcc(int arr[],int n,int i,int key,bool isprsnt){
    
    if(i==n && !isprsnt){
        cout<<"no key found\n";
        return ;
    }
    
    if(i==n){
        return ;
    }
    if(arr[i]==key){
        isprsnt=true;
        cout<<i<<" ";
       
    }
    return FindOcc(arr,n,i+1,key,isprsnt);

}
int main(){
    bool isprsnt=false;
    int n=9;
    int arr[n]={3,2,4,5,6,2,7,2,2};
    FindOcc(arr,n,0,4,isprsnt);
    return 0;
}