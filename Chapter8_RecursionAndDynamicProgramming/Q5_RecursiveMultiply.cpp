#include<iostream>
using namespace std;

int recursiveMultiply(int smaller, int bigger){
    if(smaller == 0)
        return 0;
    if(smaller ==1)
        return bigger;
    
    int s  = smaller >> 1;
    int firstHalf = recursiveMultiply(s,bigger);
    int secondHalf;
    if(smaller%2==0)
        secondHalf = firstHalf;
    else
        secondHalf = firstHalf + bigger;
    
    return firstHalf+secondHalf;

}

int main(){
    cout<<recursiveMultiply(2,100);
}