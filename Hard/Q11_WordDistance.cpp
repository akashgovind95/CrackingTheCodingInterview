#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;

unordered_map<string,vector<int>> getOccurencesOfEachWord(string book){

    unordered_map<string,vector<int>> occOfWord;
    int start=0,end;
    string temp;
    int wordCount=1;
    while(start<book.size()){
        temp="";
        end=start;
        while(end<book.size() && book[end]!=' ')temp+=book[end++];
        occOfWord[temp].push_back(wordCount);
        wordCount++;
        start=end+1;
    }
    return occOfWord;

}

int getMinDifference(vector<int> occsOfWord1,vector<int> occsOfWord2){

    int i=0,j=0;
    int minDiff = INT_MAX;
    while(i<occsOfWord1.size() && j<occsOfWord2.size()){
        if(abs(occsOfWord1[i]-occsOfWord2[j])<minDiff)
            minDiff=abs(occsOfWord1[i]-occsOfWord2[j]);
        if(occsOfWord1[i]<occsOfWord2[j])i++;
        else j++;
    }
    return minDiff-1;
}

int getWordDistance(unordered_map<string,vector<int>> &occurences, string word1, string word2){
    if(occurences.count(word1)==0 || occurences.count(word2)==0){
        cout<<"Word(s) not present in the book. Hence the result is ";
        return -1;
    }
    return getMinDifference(occurences[word1],occurences[word2]);

}

int main(){
    string book="cat goes meow dog goes bow what does the cow say moo moo goes dog";
    unordered_map<string,vector<int>> occurences = getOccurencesOfEachWord(book);
    cout<<"Min difference between cat and dog is: "<<getWordDistance(occurences,"cat","dog")<<endl;
    cout<<"Min difference between dog and goes is: "<<getWordDistance(occurences,"goes","dog")<<endl;
    cout<<"Min difference between crow and giraffe is: "<<getWordDistance(occurences,"crow","giraffe")<<endl;


    
}



