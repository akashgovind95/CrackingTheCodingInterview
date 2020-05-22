#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> getKsmallest(vector<int> nums, int K){
    priority_queue<int,vector<int>> pq;

    for(auto i : nums){
        if(pq.size()<K)
            pq.push(i);
        else if(pq.top()>i){
            pq.pop();
            pq.push(i);
        }
    }

    vector<int> res;
    while(pq.size()!=0){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;

}


int main(){
    vector<int> nums = {10,9,8,7,6,5,4,4,3,2,1};
    vector<int> res = getKsmallest(nums,5);
    for(auto i : res)
        cout<<i<<" ";
}