#include<iostream>
#include<vector>
using namespace std;

int countWays(int step, int n, vector<int> &dp){
    if(step>n)
        return 0;
    if(step==n)
        return 1;
    if(dp[step]!=-1)
        return dp[step];
    return dp[step]=countWays(step+1,n,dp) + countWays(step+2,n,dp) + countWays(step+3,n,dp);

}
int tripleStep(int n){
    vector<int> dp(n+1,-1);
    return countWays(0,n,dp);
}

int main(){
    cout<<tripleStep(3)<<endl;
    cout<<tripleStep(10)<<endl;
    cout<<tripleStep(15)<<endl;
}
