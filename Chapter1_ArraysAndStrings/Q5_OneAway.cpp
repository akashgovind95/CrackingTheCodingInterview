#include<iostream>
#include<unordered_map>
using namespace std;

class solution{
    public:
        bool oneAway(string s1, string s2){
            unordered_map<char,int> m1;
            unordered_map<char,int> m2;
            int diff = 0;

            for(auto i : s1)
                m1[i]++;
            for(auto i : s2)
                m2[i]++;

            for(auto i : s1)
                if(m1[i]!=m2[i])
                    diff++;

            return diff<2?true:false;
            
        }
        
};

int main()
{
    cout<<"Case 1:"<<endl;
    string s1 = "pale";
    string s2 = "pale";
    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Is One away? Ans: "<<solution().oneAway(s1,s2)<<endl;

    cout<<"Case 2:"<<endl;
    s1 = "pale";
    s2 = "ple";
    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Is One away? Ans: "<<solution().oneAway(s1,s2)<<endl;

    cout<<"Case 3:"<<endl;
    s1 = "pale";
    s2 = "kale";
    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Is One away? Ans: "<<solution().oneAway(s1,s2)<<endl;

    cout<<"Case 4:"<<endl;
    s1 = "pale";
    s2 = "kate";
    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Is One away? Ans: "<<solution().oneAway(s1,s2)<<endl;

    cout<<"Case 5:"<<endl;
    s1 = "palet";
    s2 = "kate";
    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Is One away? Ans: "<<solution().oneAway(s1,s2)<<endl;


}
