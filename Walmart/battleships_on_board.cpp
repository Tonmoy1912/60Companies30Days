#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int i,int j,int m,int n,vector<vector<char>> &board){
        if(i<0||i>=m||j<0||j>=n){
            return ;
        }
        if(board[i][j]=='X'){
            board[i][j]='1';
            dfs(i,j+1,m,n,board);
            dfs(i,j-1,m,n,board);
            dfs(i+1,j,m,n,board);
            dfs(i-1,j,m,n,board);
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    dfs(i,j,m,n,board);
                    count++;
                }
            }
        }
        return count;
    }
};