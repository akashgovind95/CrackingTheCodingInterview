#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

void getWords(unordered_map<char,vector<char>> &T9, int idx, string inputString, string &wordSoFar, unordered_set<string> &dict, vector<string> &res){
    if(idx==inputString.size()){
        if(dict.find(wordSoFar)!=dict.end())
            res.push_back(wordSoFar);
        return;
    }

    if(inputString[idx]==1)
        getWords(T9,idx+1,inputString,wordSoFar,dict,res);
    else{
        for(auto i : T9[inputString[idx]]){
            
            wordSoFar.push_back(i);
            getWords(T9,idx+1,inputString,wordSoFar,dict,res);
            wordSoFar.pop_back();
        }
    }
}

int main(){

    unordered_map<char,vector<char>> T9;
    unordered_set<string> dict;
    vector<string> res;
    string wordSoFar;
    string inputString = "8733";
    T9['2']={'a','b','c'};
    T9['3']={'d','e','f'};
    T9['4']={'g','h','i'};
    T9['5']={'j','k','l'};
    T9['6']={'m','n','o'};
    T9['7']={'p','q','r','s'};
    T9['8']={'t','u','v',};
    T9['9']={'w','x','y','z'};
    dict.insert("tree");
    dict.insert("used");
    getWords(T9,0,inputString,wordSoFar,dict,res);
    cout<<"Input String: "<<inputString<<endl;
    cout<<"Valid words found: ";
    for(auto i:res)
        cout<<i<<" ";


       
}
