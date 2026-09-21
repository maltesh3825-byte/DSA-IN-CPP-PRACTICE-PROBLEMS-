//counting sort
#include<iostream>
#include<climits>
using namespace std;

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
void counting(int arr[],int n){
    int minv= INT_MAX;
    int freq[10000]={0};
    int maxv= INT_MIN;

    for(int i =0;i<n;i++){
         freq[arr[i]]++;
        minv = min(arr[i],minv);
        maxv = max(arr[i],maxv);
    }
    
    for(int i = minv,j=0;i<=maxv;i++ ){
        while(freq[i]>0){
            arr[j]=i;
            freq[i]--;
            j++;
        }
    }
    print(arr,n);
}

int main(){
    int arr[8]= {1,4,1,3,2,4,3,7};
    counting(arr,8);
    return 0;
}