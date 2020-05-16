/*
To get zeros, its better to count 5's. For each number, keep dividing the number by 5 and adding it to the result while the number is greater than or equal to 5.
*/


#include<iostream>
using namespace std;

int getTrailingZeros(int n){
    int res = 0;
    while(n>=5){
        res+=n/5;
        n=n/5;
    }
    return res;
}

int main(){
    cout<<getTrailingZeros(3)<<endl;
    cout<<getTrailingZeros(31)<<endl;
    cout<<getTrailingZeros(125)<<endl;
}