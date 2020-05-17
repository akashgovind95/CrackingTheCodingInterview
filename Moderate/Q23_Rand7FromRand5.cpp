#include<iostream>
#include<vector>
using namespace std;
int rand5(){
    return (rand() % (4 - 0 + 1)) + 0;
}
int rand7(){

    vector<vector<int>> random = {{0,1,2,3,4},{5,6,0,1,2},{3,4,5,6,0},{1,2,3,4,5},{6,-1,-1,-1,-1}};
    int result=-1;
    while(result==-1){
        int x = rand5();
        int y = rand5();
        result = random[x][y];
    }

    return result;
}

int main(){
    for(int i=0;i<50;i++)
        cout<<rand7()<<endl;
}