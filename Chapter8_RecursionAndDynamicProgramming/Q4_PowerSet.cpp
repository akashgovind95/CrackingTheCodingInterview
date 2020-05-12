#include<iostream>
#include<vector>
using namespace std;

void powerSet(vector<int> input, int idx, vector<int> temp, vector<vector<int>> &result){
    result.push_back(temp);
    if(idx==input.size())
        return;
    temp.push_back(input[idx]);
    powerSet(input,idx+1,temp,result);
}

int main(){
    vector<vector<int>> result;
    vector<int> input = {1,2,3};
    for(int i=0;i<input.size();i++)
        powerSet(input,i+1,{input[i]},result);
    
    for(auto sets : result){
        for(auto val : sets)
            cout<<val<<" ";
        cout<<endl;
    
    }
}