#include<iostream>
#include<unordered_map>
using namespace std;

void getHitCount(string ac, string gu){ //ac=actual string | gu=guessed string
    unordered_map<char,int> hits;

    int acHits= 0;
    int psuedoHits= 0;

    for(int i=0;i<ac.size();i++){
        if(ac[i]==gu[i]){
            ac[i]='#';
            gu[i]='#';
            acHits++;
        }
        else
            hits[ac[i]]++;
    }

    for(auto i : gu){
        if(i!='#' && hits[i]>0){
            psuedoHits++;
            hits[i]--;
        }
    }

    cout<<acHits<<" "<<psuedoHits;

}

int main(){
    getHitCount("RGBYR","GGRRY");
}

