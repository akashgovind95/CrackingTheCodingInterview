#include<iostream>
#include<vector>
using namespace std;
enum colors{
    CYAN,MAGENTA,YELLOW,BLACK
};
void fillColorHelper(vector<vector<colors>>& image, int currRow, int currCol, int totalRows, int totalCols, colors originalColor, colors newColor){
        cout<<currRow<<"-"<<currCol<<endl<<"Hello";
        if(currRow>=totalRows || currRow<0 || currCol>=totalCols || currCol<0 || image[currRow][currCol]!=originalColor)
            return;
        
        image[currRow][currCol] = newColor;
        fillColorHelper(image,currRow+1,currCol,totalRows,totalCols,originalColor,newColor);
        fillColorHelper(image,currRow-1,currCol,totalRows,totalCols,originalColor,newColor);
        fillColorHelper(image,currRow,currCol+1,totalRows,totalCols,originalColor,newColor);
        fillColorHelper(image,currRow,currCol-1,totalRows,totalCols,originalColor,newColor);
    }

int main(){
    vector<vector<colors>> grid = {{MAGENTA,MAGENTA,MAGENTA},{MAGENTA,CYAN,CYAN}};
    int totalRows = grid.size();
    int totalCols = grid[0].size();
    colors originalColor = CYAN;
    colors newColor = BLACK;
    /*

    paintFill(grid,i,j,totalRows,totalCols,originalColor,newColor);

    for(int i=0;i<totalRows;i++){
        for(int j = 0;j<totalCols;j++){
            if(grid[i][j]==originalColor)
                paintFill(grid,i,j,totalRows,totalCols,originalColor,newColor);
        }
    }
    */

    fillColorHelper(grid,1,1,totalRows,totalCols,originalColor,newColor);
    for(auto i : grid){
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
}
