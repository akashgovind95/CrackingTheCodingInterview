#include<iostream>
#include<vector>
using namespace std;

int magicIndex(vector<int> arr, int start, int end){

    if(end<start)
        return -1;
    int mid = (start+end)/2;
    if(arr[mid]==mid)
        return mid;
    if(arr[mid]<mid)
        return magicIndex(arr,mid+1,end);
    return magicIndex(arr,start,mid-1);

}

int main(){
    vector<int> input{-40,-20,-1,1,2,3,5,7,9,12,13};
    cout<<magicIndex(input,0,input.size()-1);
}