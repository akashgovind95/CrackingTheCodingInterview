#include<iostream>
#include<unordered_map>
using namespace std;

class solution{
    public:
        bool checkRotation(string s1, string s2){
            string combinedString = s1+s1;
            if(combinedString.find(s2)!=-1)
                return true;
            return false;
        }
        
};

int main()
{
    cout<<"Case 1:"<<endl;
    string s1 = "abcd";
    string s2 = "bcda";
    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Is rotated? Ans: "<<solution().checkRotation(s1,s2)<<endl;

    cout<<"Case 2:"<<endl;
    s1 = "AbCd";
    s2 = "bCdA";
    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Is rotated? Ans: "<<solution().checkRotation(s1,s2)<<endl;

    cout<<"Case 3:"<<endl;
    s1 = "A";
    s2 = "B";
    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Is rotated? Ans: "<<solution().checkRotation(s1,s2)<<endl;


}
