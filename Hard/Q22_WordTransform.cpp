#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

int minDistance(vector<string> Words, string start, string end){
    unordered_set<string> wordSet;
    int res=0;
    queue<string> q;

    for(auto word : Words)
        wordSet.insert(word);
    
    q.push(start);
    
    while(!q.empty()){
        res++;
        int qsize = q.size();
        for(int i=0;i<qsize;i++){
            string curr=q.front();
            q.pop();
            if(curr==end)
                return res;
            for(int i=0;i<curr.size();i++){
                char temp=curr[i];
                for(char j='a';j<='z';j++){
                    curr[i]=j;
                    if(wordSet.find(curr)!=wordSet.end()){
                        q.push(curr);
                        wordSet.erase(curr);
                    }
                }
                curr[i]=temp;
            }
        }
    }

    return 0;

}

int main(){
    vector<string> vec ={"hot","dot","dog","lot","log","cog"};
    string start = "hit";
    string end = "cog";
    cout<<minDistance(vec,start,end);
}
