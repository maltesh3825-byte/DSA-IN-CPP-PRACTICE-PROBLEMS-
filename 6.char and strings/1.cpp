//lower to uppercase and vice-vsersa
#include<iostream>
#include<cstring>

using namespace std;

 
void toupper(char *arr,int n){
    for(int i=0;i<n;i++){
        char ch = arr[i];
        if(ch>'A'&&ch<'Z'){//if(ch>a && ch<z) for upper to lower
            continue;
        }
        else{
            arr[i] = ch - 'a' + 'A';//arr[i] = ch - 'A' + 'a' for upper to lower
        }

    }
}
int main(){
    char arr[]= "hEllO";
    toupper(arr,strlen(arr));
    cout<<arr;
    return 0;
}