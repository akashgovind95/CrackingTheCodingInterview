#include<iostream>
#include<unordered_set>
#include<vector>
#include<ctime>
using namespace std;

unordered_set<int> getSubset(vector<int> &set, int m){
    unordered_set<int> subset;
    srand(time(0)); 
    while(subset.size()!=m)
        subset.insert(set[rand()%set.size()]);
    return subset;
}

int main(){

    int n=50;
    int m=10;
    vector<int> set;
    for(int i=1;i<=n;i++)
        set.push_back(i);
    unordered_set<int> subset = getSubset(set,m);

    for(auto i : subset)
        cout<<i<<" ";

}