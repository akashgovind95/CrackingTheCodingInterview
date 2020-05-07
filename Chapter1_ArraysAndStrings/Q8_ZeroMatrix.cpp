#include<iostream>
#include<vector>
using namespace std;

class solution{
    public:
        void makeRowColZero(vector<vector<int>> &mat, int &totalRows, int &totalCols, int &row, int &col){
            for(int i = 0;i<totalRows;i++)
                mat[i][col]=0;
            for(int i = 0;i<totalCols;i++)
                mat[row][i]=0;
        }
        void zeroMatrix(vector<vector<int>> &mat){
            if(mat.empty())
                return;
            int totalRows  =mat.size();
            int totalCols = mat[0].size();

            vector<vector<int>> allZeroIndices;

            for(int i =0;i<totalRows;i++)
                for(int j=0;j<totalCols;j++)
                    if(mat[i][j]==0)
                        allZeroIndices.push_back({i,j});
            
            for(auto i : allZeroIndices)
                makeRowColZero(mat,totalRows,totalCols,i[0],i[1]);

        }
};

int main(){
    cout<<"Case 1: "<<endl;
    cout<<"Before:"<<endl;
    vector<vector<int>> input = {{1,2,3},{4,0,6},{7,8,9}};
    for(auto i : input){
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    solution().zeroMatrix(input);
    cout<<endl<<"After:"<<endl;
    for(auto i : input){
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }

    cout<<"Case 2: "<<endl;
    cout<<"Before:"<<endl;
    input = {{0,2,3},{4,0,6},{7,8,0}};
    for(auto i : input){
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    solution().zeroMatrix(input);
    cout<<endl<<"After:"<<endl;
    for(auto i : input){
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }

    
}
