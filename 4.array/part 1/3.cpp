//reverse without extra spaces
#include<iostream> 
using namespace std;
int printar(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<*(arr +i)<<",";
    }
}
int main()
{
    int arr[]={1,3,5,8,2};
    int n=sizeof(arr)/sizeof(int);
    int start =0,end=n-1;
        while(start<end){
        int temp= arr[start]; /*here instead of temp logic 
                                we can use inbuilt function swap(arr[start]=arr[end])*/                        
        arr[start]=arr[end];
        arr[end]= temp;

        start++;
        end--;

    }
    cout<<printar(arr,n);
    return 0;
}