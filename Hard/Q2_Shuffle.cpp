#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
void shuffleDeck(vector<int> &deck){
    srand(time(0)); 
    for(int i=0;i<deck.size();i++){
        int swapWith = i+(rand()%52-i);
        swap(deck[i],deck[swapWith]);
    }
}
int main(){

    vector<int> deck;
    for(int i=1;i<=52;i++)
        deck.push_back(i);
    
    shuffleDeck(deck);
    for(auto i : deck)
        cout<<i<<" ";
}
