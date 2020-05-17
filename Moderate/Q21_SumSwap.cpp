#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int getSum(vector<int> &arr){
    int sum = 0;
    for(auto i : arr)
        sum+=i;
    return sum;
}
pair<int,int> swapSum(vector<int> &A,vector<int> &B){
    int Asum = getSum(A);
    int Bsum = getSum(B);
    int diff = abs(Asum-Bsum);
    unordered_map<int,int> intCount;
    for(auto i : B)
        intCount[i]++;

    for(auto i : A)
        if(intCount[diff-i]>0)
            return make_pair(i,diff-i);

    return make_pair(0-1,-1);
}
int main(){

    vector<int> A = {4,1,2,1,1,2};
    vector<int> B = {3,6,3,3};
    pair<int,int> res = swapSum(A,B);
    cout<<res.first<<" "<<res.second;

}