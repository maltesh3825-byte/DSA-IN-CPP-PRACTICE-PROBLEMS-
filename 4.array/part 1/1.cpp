//linear search
#include<iostream>
using namespace std;
int lin(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key)
        {
            return i;
        }    
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5,6};
    int key;
    int n=sizeof(arr)/sizeof(int);
    cout<<"enter the key:\n";
    cin>>key;
    cout<<lin(arr,n,key);
    return 0;
}