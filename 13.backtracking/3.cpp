//N queens
#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<char>> board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
            
        }
        cout<<endl;
       
    }
     cout<<endl;

    cout<<"---------------";
    cout<<endl;
}
bool isSafe(vector<vector<char>> &board,int row,int col){
    int n=board.size();
    //horizontal
    for(int j=0;j<n;j++){
        if(board[row][j]=='Q'){
            return false;
        }
        
    }
    //vertical
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    //left diagonal
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    //right diagonal
    for(int i=row,j=col;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;

}
int nqueen(vector<vector<char>> &board,int row){
    
    int n=board.size();
    if(row==n){
        print(board,n);
        return 1;
    }
    int count =0;
    for(int j=0;j<n;j++){
        if(isSafe(board,row,j)){
        board[row][j]='Q';
        count+=nqueen(board,row+1);
        board[row][j]='.';   
        }

         
    }
    return count;
}
int main(){
    vector<vector<char>> board;
    int n=5;
    for(int i=0;i<n;i++){
        vector<char> newRow;
        for(int j=0;j<n;j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);

    }
   int count= nqueen(board,0);
   cout<<"possible arrangements :"<<count;
   return 0;

}

