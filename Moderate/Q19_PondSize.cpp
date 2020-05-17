#include<iostream>
#include<vector>
using namespace std;

int pondSize(vector<vector<int>> &sea, int i , int j, int m, int n){
    if(i<0 || i>=m || j<0 || j>=n || sea[i][j]!=0)
        return 0;
    sea[i][j]=-1;
    return 1 + pondSize(sea,i+1,j,m,n)+pondSize(sea,i-1,j,m,n)+pondSize(sea,i,j+1,m,n)+pondSize(sea,i,j-1,m,n)+pondSize(sea,i-1,j-1,m,n)+pondSize(sea,i-1,j+1,m,n)+pondSize(sea,i+1,j-1,m,n)+pondSize(sea,i+1,j+1,m,n);
}  

int main(){

    vector<vector<int>> sea = {{0,2,1,0},{0,1,0,1},{1,1,0,1},{0,1,0,1}};
    vector<int> res;
    int m=sea.size();
    int n=sea[0].size();
    for(int i =0;i<m;i++)
        for(int j=0;j<n;j++)
            if(sea[i][j]==0)
                res.push_back(pondSize(sea,i,j,m,n));

    for(auto i : res)
        cout<<i<<" ";

}