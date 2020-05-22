#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class synonyms{
    public:
        unordered_map<string,vector<string>> syn;
        void addEdge(string from, string to){
            syn[from].push_back(to);
            syn[to].push_back(from);
        }
};

int getUpdatedCount(unordered_map<string,int> &govList,string str, synonyms &obj,unordered_map<string,bool> &isVis){
    
    if(isVis[str])
        return 0;
    int res=govList[str];

    isVis[str]=true;
    for(auto i : obj.syn[str])
        res+=getUpdatedCount(govList,i,obj,isVis);
    return res;

}
unordered_map<string, int> getUpdatedList(unordered_map<string,int> &govList, synonyms &obj){
    unordered_map<string,bool> isVis;
    unordered_map<string,int> res;
    for(auto i : govList)
        if(!isVis[i.first])
            res[i.first]=getUpdatedCount(govList,i.first,obj,isVis);
    return res;
    
}

int main(){
    unordered_map<string,int> govList;
    govList["John"]=15;
    govList["Jon"]=12;
    govList["Chris"]=13;
    govList["Kris"]=4;
    govList["Christopher"]=19;

    synonyms obj;
    obj.addEdge("John","Jon");
    obj.addEdge("Jon","Johnny");
    obj.addEdge("Chris","Kris");
    obj.addEdge("Kris","Christopher");

    cout<<"__Original List__"<<endl;
    for(auto i : govList)
        cout<<i.first<<": "<<i.second<<endl;

    unordered_map<string,int> res = getUpdatedList(govList,obj);

    cout<<endl<<"__Updated List__"<<endl;
    for(auto i : res)
        cout<<i.first<<": "<<i.second<<endl;


    
    
}
