//trapping rain water with O(n+n+n) = O(3n) = O(n) => linear time complexity
#include<iostream>
using namespace std;

int trap(int *bar, int n){

    int leftmax[20000],rightmax[20000];
    leftmax[0]=bar[0];
    rightmax[n-1]=bar[n-1];

    for(int i=1;i<n;i++){
        leftmax[i]=max(leftmax[i-1],bar[i-1]);
    }

    for(int i=n-2;i>=0;i--){
        rightmax[i]=max(rightmax[i+1],bar[i+1]);
    }
     
    int watertrap=0;
    
    for(int i=0;i<n;i++){
       
        int curs=(min(leftmax[i],rightmax[i]))- bar[i];
        if(curs>0){
            watertrap+=curs;
        }

    }
     cout<<"water trapped = "<<watertrap;
    cout<<endl;
    return watertrap;


}
 
int main(){
    int bar[]={4,2,0,6,3,2,5};
    int n= sizeof(bar)/sizeof(int);
    trap(bar,n);
    return 0;
}
