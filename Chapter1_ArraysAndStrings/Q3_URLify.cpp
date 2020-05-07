#include<iostream>
#include<unordered_map>
using namespace std;

class solution{
    public:
        string urlify(string s, int trueLen){
            int k = s.size()-1;
            for(int i =trueLen-1;i>=0;i--){
                if(s[i]!=' ')
                    s[k--]=s[i];
                else{
                    s[k--]='0';
                    s[k--]='2';
                    s[k--]='%';
                }
            }
            return s;
        }

};

int main(){
    //Case 1
    string input = "Mr John Smith    ";
    int trueLen = 13;
    cout<<"String: "<<input<<endl;
    cout<<"URLified string: "<<solution().urlify(input,trueLen)<<endl;

    return 0;
}
