#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int maxSum(int idx, int prev, vector<int> &nums, int soFar, int &mSum, vector<vector<int>> &dp){
    if(idx == nums.size()-1 || idx == nums.size()-2)
        return nums[idx]+soFar;
    
    if(dp[prev][idx]!=-1)
      return dp[prev][idx];

    for(int i=idx+2;i<nums.size();i++){
        dp[idx][i] = maxSum(i,idx,nums,soFar+nums[idx],mSum,dp);
        mSum=max(mSum,dp[idx][i]);
    }
    return mSum;
    
}

int massage(vector<int> &nums){
    vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
    int mSum = 0;
    for(int i=0;i<nums.size();i++)
        maxSum(i,i,nums,0,mSum,dp);
    return mSum;
}

int main(){
    vector<int> nums = {30,15,60,75,45,15,50,45};
    cout<<massage(nums);
}