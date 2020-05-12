#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void permWithDups(string s,unordered_map<int,int> &count){

    unordered_map<int,int>::iterator it;
    for(it=count.begin();it!=count.end();it++)
        if(it->second!=0)
            break;
    
    if(it==count.end())
        cout<<s<<endl;
    
    for(;it!=count.end();it++){
        if(it->second!=0){
            it->second--;
            s.push_back(it->first);
            permWithDups(s,count);
            s.pop_back();
            it->second++;
        }
    }

}
int main(){
    
    string input = "112";
    string s = "";
    unordered_map<int,int> count;
    for(auto i : input)
        count[i]++;
    permWithDups(s,count);
    
}