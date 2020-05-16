#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define INT_MIN -65535

/*
This program is similar to max platform needed.
*/

int getMaxYearBruteForce(vector<int> &B,vector<int> &D){

    //Step1 : Get min year from B
    int start  = *min_element(B.begin(),B.end());
    //Step2 : Get max year from B
    int end  = *max_element(D.begin(),D.end());
    unordered_map<int,int> year;
    
    int maxAlive = INT_MIN;
    int maxAliveYear;
    //Step3 : For each year betweem start and end (including both) check how many people were alive. O((start-end)xN) where N is the length for the array.
    for(int i =start;i<=end;i++){
        for(int j = 0;j<B.size();j++){
            if(i>=B[j] && i<=D[j]){
                year[i]++;
                if(year[i]>maxAlive){ //Step4: take max of all the alive people so far and store the year everytime a new max is found.
                    maxAlive=year[i];
                    maxAliveYear=i;
                }
            }
        }
    }

    return maxAliveYear; //Step5 : return the year with max people alive
}

int getMaxYearOptimized(vector<int> &B, vector<int> &D){
    sort(B.begin(),B.end());
    sort(D.begin(),D.end()); //Step1 : Sort both of the arrays
    int maxAlive = INT_MIN,currAlive = 1,maxAliveYear;
    int j = 0;
    for(int i = 1;i<B.size();i++){ //Run a loop in which for each birth year, increase the currAlive and for each death year, decrease the currAlive.
        if(D[j]<B[i]){
            currAlive--;
            j++;
        }
        currAlive++;
        if(currAlive>maxAlive){  //Whenever currAlive changes, update the maxAlive with max(maxAlive, currAlive). If maxAlive changes, update maxAliveYear
            maxAlive=currAlive;
            maxAliveYear=B[i];
        }
    }

    return maxAliveYear; //return maxAliveYear
}
int main(){
    vector<int> B = {1982,1923,1988,1910,1990,2004};
    vector<int> D = {2017,2004,2015,1988,2005,2010};
    cout<<"As per Brute Force method: "<<getMaxYearBruteForce(B,D)<<endl;
    cout<<"As per optimized method: "<<getMaxYearOptimized(B,D);

}