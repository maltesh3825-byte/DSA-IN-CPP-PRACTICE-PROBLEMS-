//spiral matrix
#include<iostream>
#include<string>
using namespace std;
void spiral(int matrix[][4],int n,int m){
    int srow=0,scol=0,endr=n-1,endcol=m-1;
    while(srow<=endr&&scol<=endcol){
        //top
        for(int j = scol;j<=endcol;j++){
            cout<<matrix[srow][j]<<" ";
        }

        //right
        for(int i = srow+1;i<=endr;i++){
            cout<<matrix[i][endcol]<<" ";
        }
        //bottom
        
        for(int j = endcol-1;j>=scol;j--){
            if(srow==endr){
                break;
            }
            cout<<matrix[endr][j]<<" ";
        }
        //left
        for(int i = endr-1;i>=srow+1;i--){
            if(scol==endcol){
                break;
            }
            cout<<matrix[i][scol]<<" ";
        }
        srow++;
        scol++;
        endr--;
        endcol--;

    }

}

int main(){
    int matrix[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    spiral(matrix,4,4);
    return 0;
}