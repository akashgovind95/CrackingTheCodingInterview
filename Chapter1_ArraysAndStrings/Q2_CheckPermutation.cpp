#include<iostream>
#include<unordered_map>
using namespace std;

class solution{
    public:
        bool checkPermutation(string s1, string s2){
            if(s1.size()!=s2.size())
                return false;
            unordered_map<char,int> charCount;
            for(int i=0;i<s1.size();i++){
                charCount[s1[i]]++;
                charCount[s2[i]]--;
            }
            
            for(auto i : charCount)
                if(i.second!=0)
                    return false;  
            return true;
                
        }

};

int main(){
    cout<<"Case 1: "<<endl;
    string s1 = "abcde";
    string s2 = "eabcd";
    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Is permutation? Ans:"<<solution().checkPermutation(s1,s2)<<endl;

    cout<<"Case 2: "<<endl;
    s1 = "abcde";
    s2 = "abcdf";
    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Is permutation? Ans:"<<solution().checkPermutation(s1,s2)<<endl;

    cout<<"Case 3: "<<endl;
    s1 = "abcde";
    s2 = "abcd";
    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Is permutation? Ans:"<<solution().checkPermutation(s1,s2)<<endl;


    return 0;
}
