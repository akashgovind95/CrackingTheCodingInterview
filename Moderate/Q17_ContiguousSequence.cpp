#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int maxSubArray(vector<int> &arr){
    int maxSum = INT_MIN;
    int currSum = arr[0];
    for(auto i : arr){
        currSum=max(currSum+i,i);
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
}

int main(){
    vector<int> arr = {2,-8,3,-2,4,-10};
    cout<<"Array: ";
    for(auto i : arr)
        cout<<i<<" ";
    cout<<endl;
    cout<<"Sum of the longest contiguous sequence is: "<<maxSubArray(arr);
}