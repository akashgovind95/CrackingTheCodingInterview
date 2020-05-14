#include<vector>
#include<iostream>
using namespace std;

int searchInRotatedSortedArray(vector<int> &input, int target){

    int start = 0;
    int end = input.size()-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(input[mid]==target)
            return mid;
        if(input[mid]>=input[start]){
            if(target>=input[start] && target<input[mid])
                end=mid-1;
            else
                start=mid+1;
        }
        else{
            if(target>input[mid] && target<=input[end])
                start=mid+1;
            else
                end=mid-1;
        }
    }

    return -1;
}

int main(){

    vector<int> input = {15,16,20,25,1,3,4,5,7,10,14};
    cout<<searchInRotatedSortedArray(input,15)<<endl;
    cout<<searchInRotatedSortedArray(input,16)<<endl;
    cout<<searchInRotatedSortedArray(input,1)<<endl;
    cout<<searchInRotatedSortedArray(input,3)<<endl;
    cout<<searchInRotatedSortedArray(input,7)<<endl;
    cout<<searchInRotatedSortedArray(input,10)<<endl;
    cout<<searchInRotatedSortedArray(input,14)<<endl;
}