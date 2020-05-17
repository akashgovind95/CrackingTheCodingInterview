#include<iostream>
#include<vector>
using namespace std;

enum color{
    BLACK,WHITE
};
enum direction{
    UP,DOWN,LEFT,RIGHT
};

void startAutomaton(int K){

    vector<vector<color>> grid(11,vector<color>(11,WHITE));
    int x=5,y=5;
    direction dir=RIGHT;

    while(K){
        if(grid[x][y]==WHITE){
            grid[x][y]=BLACK;
            if(dir==RIGHT){
                x++;
                dir=DOWN;
            }
            else if(dir==DOWN){
                y--;
                dir=LEFT;
            }
            else if(dir==LEFT){
                x--;
                dir=UP;
            }
            else
            {
                y++;
                dir=RIGHT;
            }
            
        }

        else{
            grid[x][y]=WHITE;
            if(dir==RIGHT){
                x--;
                dir=UP;
            }
            else if(dir==UP){
                y--;
                dir=LEFT;
            }
            else if(dir==LEFT){
                x++;
                dir=DOWN;
            }
            else
            {
                y++;
                dir=RIGHT;
            }
            
        }
        K--;
    }

    for(int i =0;i<11;i++){
        for(int j=0;j<11;j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }

}

int main(){
    startAutomaton(200);
}