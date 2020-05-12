#include<iostream>
#include<vector>
using namespace std;

int countWays(int curr, int currCoin, int amount, vector<int> &coins, vector<vector<int>> &dp){
    if(curr==amount)
        return 1;
    if(dp[curr][currCoin]!=-1)
        return dp[curr][currCoin];
    
    dp[curr][currCoin] = 0;

    for(int i =currCoin;i<coins.size();i++)
        if(curr+coins[i]<=amount)
            dp[curr][currCoin] += countWays(curr+coins[i],i,amount,coins,dp);
    
    return dp[curr][currCoin];
}
int main(){
    int amount = 10;
    vector<int> coins = {1,5,10,25};
    vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1,-1));
    cout<<countWays(0,0, amount, coins, dp);
}