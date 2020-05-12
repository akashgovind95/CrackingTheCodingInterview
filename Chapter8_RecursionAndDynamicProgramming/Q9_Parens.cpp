#include<iostream>
using namespace std;

void parens(string &s, int open, int close){

    if(open ==0 && close==0){
        cout<<s<<endl;
        return;
    }

    if(open > 0){
        s.push_back('(');
        parens(s,open-1,close);
        s.pop_back();
    }
    if(close>open){
        s.push_back(')');
        parens(s,open,close-1);
        s.pop_back();
    }
    
}

int main(){
    string s = "";
    parens(s,3,3);
}