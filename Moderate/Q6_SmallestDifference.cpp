#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INT_MAX 2147483647;

pair<int,int> minDiffHelper(vector<int> v1, vector<int> v2){
    int min1,min2;
    int i = 0;
    int j = 0;
    int minDiff = INT_MAX;
    while(i<v1.size() && j<v2.size()){
        if(abs(v1[i]-v2[j]) < minDiff){
            minDiff = abs(v1[i]-v2[j]);
            min1 = v1[i];
            min2 = v2[j++];
        }
        else
            i++;
    }
    return make_pair(min1,min2);

}

pair<int,int> getMinDiff(vector<int> v1,vector<int> v2){
    if(v1.empty() || v2.empty())
        return make_pair(-1,-1);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    return minDiffHelper(v1,v2);
}
int main(){

    vector<int> v1 = {1,2,15,11};
    vector<int> v2 = {4,12,19,23,127,235};
    pair<int,int> minPair = getMinDiff(v1,v2);
    cout<<minPair.first<<" "<<minPair.second;

}