#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int getMaxlen(string str){
    unordered_map<int,int> m;
    int sum=0,maxLen=0;
    m[0]=-1;
    for(int i=0;i<str.size();i++){
        sum+=isdigit(str[i])?1:-1;
        if(m.count(sum)!=0)
            maxLen=max(maxLen,i-m[sum]);
        else
            m[sum]=i;
    }

    return maxLen;

}
int main(){
    vector<string> vec = {"a1b2c3d4","11111abc11111","111111","abcabc"};
    for(auto i : vec){
        cout<<"string: "<<i<<endl;
        cout<<"Longest string with equal letters and numbers "<<getMaxlen(i)<<endl;
    }
}
