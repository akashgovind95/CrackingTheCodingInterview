#include<iostream>
#include<unordered_map>
using namespace std;

class solution{
    public:
        bool isUnique(string input){
            unordered_map<char,int> charCount;
            for(auto i : input){
                if(charCount[i]==1)
                    return false;
                charCount[i]=1;
            }
            return true;
                
        }

};

int main(){
    //Case 1
    string input = "abcd";
    cout<<"String: "<<input<<endl;
    cout<<"Is Unique? "<<solution().isUnique(input)<<endl;

    input = "abcda";
    cout<<"String: "<<input<<endl;
    cout<<"Is Unique? "<<solution().isUnique(input)<<endl;


    return 0;
}
