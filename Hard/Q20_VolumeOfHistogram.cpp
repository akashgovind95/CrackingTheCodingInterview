#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int getVolume(vector<int> &height){

    if(height.size()==0)
        return 0;
    vector<int> lMax(height.size(),0);
    vector<int> rMax(height.size(),0);
    int res = 0;

    lMax[0]=height[0];
    rMax[height.size()-1]=height[height.size()-1];

    for(int i=1;i<height.size();i++)
        lMax[i] = max(lMax[i-1],height[i]);
    for(int i=height.size()-2;i>=0;i--)
        rMax[i] = max(rMax[i+1],height[i]);
    for(int i=0;i<height.size();i++)
        res+=min(lMax[i],rMax[i])-height[i];
    
    return res;
}

int main(){
    vector<int> vec = {0,0,4,0,0,6,0,0,3,0,5,0,1,0,0,0};
    cout<<getVolume(vec);
}