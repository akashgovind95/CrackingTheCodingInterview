#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool compare(unordered_map<int,int> &m1, unordered_map<int,int> &m2, vector<int> &vec2){
    for(auto i : m1)
            if(m2[i.first]<i.second)
                return false;
        return true;
}
pair<int,int> getSmallestSubarray(vector<int> &vec1, vector<int> &vec2){
    
    if(vec2.size()==0)
        return make_pair(-1,-1);
    if(vec2.size()>vec1.size()) 
        return make_pair(-1,-1);
    unordered_map<int,int> m1;
    unordered_map<int,int> m2;
    for(auto i : vec2)
        m1[i]++;
    int start=0,begin=0,maxLen=100,end=0;
    while(end<vec1.size()){

        while(end<vec1.size() && !compare(m1,m2,vec2))m2[vec1[end++]]++;
        while(start<end && compare(m1,m2,vec2)){
            if(maxLen>end-start){
                maxLen = end-start;
                begin=start;
            }
            m2[vec1[start++]]--;
        }
        
    }
    return make_pair(begin,begin+maxLen-1);
}

int main(){
    //Case 1:
    vector<int> vec1 = {7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7};
    vector<int> vec2 = {1,5,9,1};
    pair<int,int> minSubArray = getSmallestSubarray(vec1,vec2);
    cout<<minSubArray.first<<" "<<minSubArray.second<<endl;

    //Case 2:
    vec1 = {1,2};
    vec2 = {1};
    minSubArray = getSmallestSubarray(vec1,vec2);
    cout<<minSubArray.first<<" "<<minSubArray.second<<endl;
}