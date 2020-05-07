#include<iostream>
#include<vector>
using namespace std;

class solution{
    public:
        void rotateMatrix(vector<vector<int>> &mat){
            if(mat.empty())
                return;
            int totalRows = mat.size();
            int totalCols = mat[0].size();

            for(int i=0;i<totalRows;i++)
                for(int j=0;j<i;j++)
                    swap(mat[i][j],mat[j][i]);
            
            for(int i=0;i<totalRows;i++){
                int start = 0;
                int end = totalCols-1;
                while(start<end)
                    swap(mat[i][start++],mat[i][end--]);
            }
            
        }
};

int main(){
    cout<<"Before Rotation:"<<endl;
    vector<vector<int>> input = {{1,2,3},{4,0,6},{7,8,9}};
    for(auto i : input){
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    solution().rotateMatrix(input);
    cout<<endl<<"After Rotation:"<<endl;
    for(auto i : input){
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }

  

    
}
