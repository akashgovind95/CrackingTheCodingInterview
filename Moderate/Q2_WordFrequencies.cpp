#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

unordered_map<string, int> getWordFrequency(vector<string> &book){
    unordered_map<string, int> wordMap;
    if(book.size()==0)
        return wordMap;
    
    for(auto i : book)
        wordMap[i]++;

    return wordMap;

}

int main(){
    vector<string> book = {"Hello", "how", "are", "you", "you"};
    unordered_map<string,int> wordMap = getWordFrequency(book);
    for(auto i : wordMap)
        cout<<i.first<<": "<<i.second<<endl;
    
}