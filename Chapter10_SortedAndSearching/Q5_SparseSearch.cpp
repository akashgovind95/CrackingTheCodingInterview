#include<iostream>
#include<vector>
using namespace std;

int findString(vector<string> arr, string target){
    int start = 0;
    int end = arr.size()-1;
    while(start<=end){
        int mid =(start+end)/2;
        if(arr[mid]==""){
            int right = mid+1;
            int left = mid-1;
            while(1){
                if(right>end && left<start)
                    return -1;
                else if(right <= end && arr[right]!=""){
                    mid=right;
                    break;
                }
                else if(left>=start && arr[left]!=""){
                    mid=left;
                    break;
                }
                right++;
                left--;
            }
        }

        if(arr[mid]==target)
            return mid;
        else if(arr[mid]>target)
            end=mid-1;
        else
            start=mid+1;
    }
    return -1;
}
int main(){
    vector<string> input = {"at","","","","ball","","","car","","","dad","","","to"};
    cout<<findString(input,"at")<<endl;
    cout<<findString(input,"ball")<<endl;
    cout<<findString(input,"car")<<endl;
    cout<<findString(input,"dad")<<endl;
    cout<<findString(input,"to")<<endl;
    cout<<findString(input,"bro")<<endl;
}
