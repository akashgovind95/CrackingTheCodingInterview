#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countPaths(vector<vector<int>>& grid, int i, int j, int totalRows, int totalCols, vector<vector<int>> &dp){
        if(i>=totalRows || j>=totalCols)
            return 0;
        if(grid[i][j]==1)
            return dp[i][j] = 0;
        if(i==totalRows-1 && j==totalCols-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]= countPaths(grid,i+1,j,totalRows,totalCols,dp)+countPaths(grid,i,j+1,totalRows,totalCols,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        vector<vector<int>> dp(totalRows+1,vector<int>(totalCols,-1));
        return countPaths(grid,0,0,totalRows,totalCols,dp);
    }
};

int main(){
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    cout<<Solution().uniquePathsWithObstacles(grid);
}