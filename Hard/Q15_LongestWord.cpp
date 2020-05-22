#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool helper(string s, bool isOriWord, unordered_map<string,bool> m){
    if(m.count(s)>0 && !isOriWord)
        return m[s];
    for(int i=1;i<s.size();i++){
        string left = s.substr(0,i);
        string right = s.substr(i,s.size()-1);
        if(m.count(left) && m[left]==true && helper(right,false,m))
            return true;
    }
    m[s]=false;
    return false;

}
vector<string> GetAllCombinedWords(vector<string> words){
    unordered_map<string,bool> m;
    vector<string> res;
    for(auto i : words)
        m[i]=true;
    for(auto i : words){
        if(helper(i,true, m))
            res.push_back(i);
    }
    return res;
}

int main(){
    vector<string> input ={"dog","walk","walker","dogwalker","cat"};
    vector<string> res = GetAllCombinedWords(input);
    for(auto i : res)
        cout<<i<<endl;
    
}
