#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

 unordered_map<int,int> getPairs(vector<int> &arr, int target){
     unordered_map<int,int> m;
     unordered_map<int,int> res;
     for(auto i : arr){
         if(m.count(target-i)!=0){
             res[i]=target-i;    
         }
         else
            m[i]++;
     }

     return res;
 }

 int main(){
     vector<int> arr = {1,2,3,4,4,5,6,7};
     unordered_map<int,int> res = getPairs(arr,8);

     for(auto i : res){
         cout<<i.first<<" "<<i.second<<endl;
     }

 }