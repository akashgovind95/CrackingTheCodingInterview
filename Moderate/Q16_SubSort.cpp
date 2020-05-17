#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int getMax(vector<int> arr,int start, int end){
    int Max=INT_MIN;
    for(int i =start;i<=end;i++)
        Max=max(Max,arr[i]);
    return Max;
}

int getMin(vector<int> arr,int start, int end){
    int Min=INT_MAX;
    for(int i =start;i<=end;i++)
        Min=min(Min,arr[i]);
    return Min;
}

void getMinSubArrayToSort(vector<int> &arr){

    int leftEnd,rightStart,middleStart,middleEnd,middleMin,middleMax,i=1;
    for(;i<arr.size();i++)
        if(arr[i]<arr[i-1])
            break;
    leftEnd = i-1; 

    i=arr.size()-2;
    for(;i>=0;i--)
        if(arr[i]>arr[i+1])
        break;
    rightStart=i+1;

    middleMin = getMin(arr,leftEnd+1,rightStart-1);
    middleMax = getMax(arr,leftEnd+1,rightStart-1);

    i=0;
    for(;i<arr.size();i++)
        if(arr[i]>middleMin)
            break;
    middleStart=i;
    
    i=arr.size()-1;
    for(;i>=0;i--)
        if(arr[i]<middleMax)
            break;
    middleEnd=i;

    cout<<middleStart<<" "<<middleEnd<<endl;

}

int main(){
    //basically we have to divide array in 3 parts
    //LEFT,MIDDLE and RIGHT
    vector<int> arr1 = {1,2,4,7,10,11,7,12,6,12,18,19};
    vector<int> arr2 = {1,2,3,4,5,4,10,9,8,7,6,5,4,11,12};
    getMinSubArrayToSort(arr1);
    getMinSubArrayToSort(arr2);
     

}

