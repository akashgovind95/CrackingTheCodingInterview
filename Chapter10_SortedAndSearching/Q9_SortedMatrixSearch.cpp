#include<vector>
#include<iostream>
using namespace std;


int search(vector<vector<int>> &grid, int target){
    if(grid.empty())
        return -1;
    int m = grid.size();
    int n = grid[0].size();

    if(target<grid[0][0] || target>grid[m-1][n-1])
        return -1;
    int i = 0;
    int j = n-1;
    while(i<m && j>=0){
        if(target == grid[i][j])
            return 1;
        else if(target>grid[i][j])
            i++;
        else
            j--;
    }

    return 1;
}
int main(){

    vector<vector<int>> grid = {{1, 4,  7, 11, 15},{2,5, 8, 12, 19},{3, 6,  9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
    cout<<search(grid,1)<<endl;
    cout<<search(grid,9)<<endl;
    cout<<search(grid,18)<<endl;
    cout<<search(grid,30)<<endl;
    cout<<search(grid,-1)<<endl;
    cout<<search(grid,31)<<endl;

}
