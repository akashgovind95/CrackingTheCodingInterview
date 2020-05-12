#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compareBoxes(vector<int> box1, vector<int> box2){
    if(box2[0]>box1[0] && box2[1]>box1[1] && box2[2]>box1[2])
        return true;
    return false;
}

int maxHeight(vector<vector<int>> &boxes, int idx, int prevIdx, vector<vector<int>> &dp){
    //cout<<prevIdx<<"-"<<idx<<endl;
    
    if(idx==boxes.size()-1)
        return boxes[idx][2];
    
    if(dp[prevIdx][idx]!=-1)
        return dp[prevIdx][idx];
    
    int maxH = 0;
    for(int i= idx+1;i<boxes.size();i++){
        if(compareBoxes(boxes[idx],boxes[i])){
            dp[idx][i] = boxes[idx][2] + maxHeight(boxes,i,idx,dp);
            maxH=max(dp[idx][i],maxH);
        }
    }

    return maxH; 
}

static bool comp(const vector<int> &a, const vector<int> &b){
    return a[0]<b[0];
}
int main(){
    vector<vector<int>> boxes = {{1,1,1},{2,2,2},{3,3,3},{1,1,1}};
    sort(boxes.begin(),boxes.end(),comp);
    vector<vector<int>> dp(boxes.size()+1,vector<int>(boxes.size()+1,-1));
    cout<<maxHeight(boxes,0,0,dp);
}