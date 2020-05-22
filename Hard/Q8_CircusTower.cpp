#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

static bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.first>b.first;
}

void getMax(int curr, int prev, int height, vector<pair<int,int>> &ppl, int &maxHeight, vector<vector<int>> &dp){
    
    if(curr==ppl.size()-1)
        height=height+1;
    
    maxHeight=max(height, maxHeight);
    
    if(dp[curr][prev]!=-1)
        return;
    
    for(int i=curr+1;i<ppl.size();i++){
        if(ppl[curr].first>ppl[i].first && ppl[curr].second>ppl[i].second){
            getMax(i,curr,height+1,ppl,maxHeight,dp);
        }
    }
    dp[curr][prev]=maxHeight;

}
int getTallestTower(vector<pair<int,int>> &ppl){
    
    int maxHeight = 0;
    vector<vector<int>> dp(ppl.size(),vector<int>(ppl.size(),-1));
    sort(ppl.begin(),ppl.end(),comp); //sort the vector by weight
    for(int i=0;i<ppl.size();i++)
        getMax(i,i,1,ppl,maxHeight, dp);
    return maxHeight;

}

int main(){
    vector<pair<int,int>> ppl;
    ppl.push_back(make_pair(65,100));
    ppl.push_back(make_pair(70,150));
    ppl.push_back(make_pair(56,90));
    ppl.push_back(make_pair(75,190));
    ppl.push_back(make_pair(60,95));
    ppl.push_back(make_pair(68,95));
    ppl.push_back(make_pair(100,94));

    cout<<"List of people: "<<endl;
    for(auto i : ppl)
        cout<<"Weight: "<<i.first<<", Height: "<<i.second<<endl;

    cout<<"Lenght of highest tower that can be formed: "<<getTallestTower(ppl);
}
