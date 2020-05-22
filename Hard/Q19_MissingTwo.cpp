#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getSumOfArray(vector<int> &vec, int start, int end){
    int sum=0;
    for(int i=start;i<=end;i++)
        sum+=vec[i];
    return sum;

}

int getSumOfSeries(int N){
    return (N*(N+1))/2;
}

int getOneMissing(vector<int> &vec, int start, int end,int N){
    return getSumOfSeries(N) - getSumOfArray(vec,start,end);
}

int getIndex(vector<int> &vec, int K){
    for(int i=0;i<vec.size();i++)
        if(vec[i]>K)
            return i;
    return vec.size();
}

pair<int,int> getTwoMissing(vector<int> &vec, int N){

    int sumOfSeries = getSumOfSeries(N);
    int sumOfArr = getSumOfArray(vec,0,vec.size()-1);
    int sumOfMissingNumbers  = sumOfSeries - sumOfArr;
    int index = getIndex(vec,sumOfMissingNumbers/2);
    int firstMissing = getOneMissing(vec,0,index-1,sumOfMissingNumbers/2);
    int secondMissing = sumOfMissingNumbers - firstMissing;

    return make_pair(firstMissing,secondMissing);

}

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8};
    pair<int,int> res = getTwoMissing(vec,10);
    cout<<res.first<<" "<<res.second<<endl;

    vec = {1,2,3,4,5,6,9,10};
    res = getTwoMissing(vec,10);
    cout<<res.first<<" "<<res.second;
}
