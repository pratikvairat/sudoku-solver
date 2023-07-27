#include <bits/stdc++.h> 
bool isSafe(int i,int j,vector<vector<int>> & board,int val){
    for(int l=0;l<board.size();l++){
        if(board[i][l]==val){
            return false;
        }
        if(board[l][j]==val){
            return false;
        }
        if(board[3*(i/3)+l/3][3*(j/3)+l%3]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& board){
    int n=board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(board[i][j]==0){
               for(int val=0;val<=9;val++){
                   if(isSafe(i,j,board,val)){
                       board[i][j]=val;
                       bool possible=solve(board);
                       if(possible){
                           return true;
                       }else{
                           board[i][j]=0;
                       }
                   }  
               }
               return false;
           } 
        }
    }
    return true;

}
void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix

    solve(sudoku);
}
