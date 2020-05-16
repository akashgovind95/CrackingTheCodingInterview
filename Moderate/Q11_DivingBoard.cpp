#include<iostream>
#include<unordered_set>
using namespace std;

void totalWaysBruteForce(int K, int total, unordered_set<int> &totalCount){
    if(K==0){
        totalCount.insert(total);
        return;
    }
    totalWaysBruteForce(K-1,total+1,totalCount);
    totalWaysBruteForce(K-1,total+2,totalCount);
}

void totalWaysWithMemoization(int K, int total, unordered_set<int> &totalCount, unordered_set<string> &isVisited){
    
    if(K==0){
        totalCount.insert(total);
        return;
    }
    if(isVisited.find(to_string(K)+" "+to_string(total))!=isVisited.end())
        return;
    isVisited.insert(K+" "+total);
    totalWaysWithMemoization(K-1,total+1,totalCount,isVisited);
    totalWaysWithMemoization(K-1,total+2,totalCount,isVisited);
}

int main(){
    unordered_set<int> totalCount;
    int K =3;
    cout<<"BruteForce Approach"<<endl;
    totalWaysBruteForce(K,0,totalCount);
    for(auto i : totalCount)
        cout<<i<<" ";
    cout<<endl;

    cout<<"Recursion with memoization Approach"<<endl;
    unordered_set<string> isVisited;
    totalWaysWithMemoization(K,0,totalCount,isVisited);
    for(auto i : totalCount)
        cout<<i<<" ";
    cout<<endl;


    

}