#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    
    bool isGettingAttacked(int currRow, int currCol, int N, vector<string> &board){

        for(int i = 0;i<currRow;i++)
            if(board[i][currCol]=='Q')
                return true;

        int i = currRow;
        int j = currCol;
        while(i>0 && j>0){
            if(board[i-1][j-1]=='Q')
                return true;
            i--;j--;
        }

        i = currRow;
        j = currCol;
        while(i>0 && j<N-1){
            if(board[i-1][j+1]=='Q')
                return true;
            i--;j++;
        }
        return false;

}

void eightQueens(int currRow, int currCol, int N, vector<string> &board, vector<vector<string>> &res){
    
    
    //cout<<currRow<<"-"<<currCol<<endl;
    if(currRow == N-1){
        board[currRow][currCol]='Q';    
        res.push_back(board);
        board[currRow][currCol]='.';
        return;
    }

    board[currRow][currCol]='Q';
    for(int i=0;i<N;i++){
        if(i!=currCol && i!=currCol+1 && i!=currCol-1){
            if(isGettingAttacked(currRow+1, i, N, board)==false)
                eightQueens(currRow+1, i, N, board, res);
        }
    }
    board[currRow][currCol]='.';
    
}
};

int main(){
    int N = 8;
    string temp(N,'.');
    vector<string> board(N,temp);
    vector<vector<string>> res;
    for(int i=0;i<N;i++)
        Solution().eightQueens(0,i, N, board,res);
    
    
    
    int count=1;
    for(auto i: res){
        cout<<count++<<". "<<endl;
        for(auto j : i)
            cout<<j<<endl;
        cout<<endl; 
    }
    

}
