#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INT_MAX 2147483647;

pair<int,int> minDiffHelper(vector<int> v1, vector<int> v2){
    int min1,min2;
    int i = 0;
    int j = 0;
    int minDiff = 100;
    while(i<v1.size() && j<v2.size()){

        //cout<<abs(v1[i]-v2[j])<<endl;
        int diff=abs(v1[i]-v2[j]);
        if(diff<minDiff){
            minDiff=diff;
            min1=v1[i];
            min2=v2[j];
        }
        
        if(v1[i]<v2[j])
            i++;
        else
            j++;
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

    vector<int> v1 = {4,18,57};
    vector<int> v2 = {14,62};
    pair<int,int> minPair = getMinDiff(v2,v1);
    cout<<minPair.first<<" "<<minPair.second;

}