#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


void groupAnagram(vector<string> &input){
    unordered_map<string,vector<string>> aMap;
    for(auto i : input){
        string temp = i;
        sort(temp.begin(),temp.end());
        aMap[temp].push_back(i);
    }
    
    int idx = 0;
    for(auto i : aMap)
        for(auto j : i.second)
            input[idx++]=j;
    

}
int main(){

    vector<string> input = {"abc","bca","rt","qwe","ewq","acb","wqe","tr"};
    groupAnagram(input);
    for(auto i: input)
        cout<<i<<" ";
    
}
