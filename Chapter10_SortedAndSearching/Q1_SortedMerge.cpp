#include<iostream>
#include<vector>
using namespace std;

void mergeSorted(vector<int> &big, vector<int> &small){
    
    int bigSize = -1;
    for(auto i : big)
        if(i!=-1)
            bigSize++;
    int smallSize = small.size()-1;
    int last = bigSize+smallSize+1;

    while(bigSize>=0 && smallSize>=0){
        if(big[bigSize] > small[smallSize])
            big[last--]=big[bigSize--];
        else
            big[last--]=small[smallSize--];
    }
    
    while(bigSize>=0)
        big[last--]=big[bigSize--];
    
    while(smallSize>=0)
        big[last--]=small[smallSize--];
    
}

int main(){
    vector<int> big = {1,2,3,-1,-1,-1};
    vector<int> small = {2,5,6};
    mergeSorted(big,small);

    for(auto i : big)
        cout<<i<<" ";
    


}

