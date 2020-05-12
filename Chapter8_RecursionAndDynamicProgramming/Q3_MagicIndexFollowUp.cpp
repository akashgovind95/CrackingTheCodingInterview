#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int magicIndex(vector<int> arr, int start, int end){

    if(end<start)
        return -1;
    int mid = (start+end)/2;
    if(arr[mid]==mid)
        return mid;
    
    int leftIndex = min(mid-1,arr[mid]);
    int left = magicIndex(arr,start,leftIndex);
    if (left>=0)
        return left;
    int rightIndex = max(mid+1,arr[mid]);
    return magicIndex(arr,rightIndex,end);

}

int main(){
    vector<int> input{-10,-5,2,2,2,3,4,7,9,12};
    cout<<magicIndex(input,0,input.size()-1);
}