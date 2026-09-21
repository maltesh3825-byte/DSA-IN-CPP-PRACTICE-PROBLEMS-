//sudoku solver
#include<iostream>
using namespace std;
void print(int su[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<su[i][j]<<" ";
        if(j==2||j==5||j==8){
            cout<<"|";
        }
        if(j==8){
            cout<<"\n";
        }
        }
        if(i==2||i==5||i==8){
            cout<<"---------------------\n";
        }


    
    }

}
bool isSafe(int sudoku[][9],int r,int c,int dig){
    //vertical
    for(int i=0;i<9;i++){
        if(sudoku[i][c]==dig){
            return false;
        }
    }
    //horizontal
    for(int j=0;j<9;j++){
        if(sudoku[r][j]==dig){
            return false;
        }
    }
    //grid
    int sr=(r/3)*3;
    int sc=(c/3)*3;
    for(int i=sr;i<sr+2;i++){
        for(int j=sc;j<sc+2;j++){
            if(sudoku[i][j]==dig){
                return false;
            }
        }
    }
    return true;
}
bool sudokusolver(int sudoku [][9],int row,int col){
    if(row==9){
        //sudoku solved
        print(sudoku);
        return true;
    }
    int nxtrow=row;
    int nxtcol=col+1;
    if(col+1==9){
        nxtrow=row+1;
        nxtcol=0;
    }
    if(sudoku[row][col]!=0){
        return sudokusolver(sudoku,nxtrow,nxtcol);

    }
    for(int dig=1;dig<=9;dig++){
        if(isSafe(sudoku,row,col,dig)){
            sudoku[row][col]=dig;
            if(sudokusolver(sudoku,row,col)){
                return true;
            }
            sudoku[row][col]=0;
        }
    }
        return false;

}
int main(){
    int sudoku[9][9]={{0,0,8,0,0,0,0,0,0},
                     {4,9,0,1,5,7,0,0,2},
                     {0,0,3,0,0,4,1,9,0},
                     {1,8,5,0,6,0,0,2,0},
                     {0,0,0,0,2,0,0,6,0},
                     {9,6,0,4,0,5,3,0,0},
                     {0,3,0,0,7,2,0,0,4},
                     {0,4,9,0,3,0,0,5,7},
                     {8,2,7,0,0,9,0,1,3}  };

    sudokusolver(sudoku,0,0);
    return 0;
}