#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool toPush(char stackTop, char sign){
    if(stackTop=='-' || stackTop=='+'){
        if(sign=='*' || sign=='/')
            return true;
        return false;
    }
    return false;

}
float getRes(stack<float> &num, stack<char> &sign){  
    float operand2 = num.top();
    num.pop();
    float operand1 =num.top();
    num.pop();
    char operatr = sign.top();
    sign.pop();
    if(operatr=='+')
        return operand1+operand2;
    if(operatr=='-')
        return operand1-operand2;
    if(operatr=='*')
        return operand1*operand2;
    return operand1/operand2;
}

float calc(string exp){
    stack<float> num;
    stack<char> sign;
    int i=  0;
    
    while(i<exp.size()){
        string temp="";
        if(isdigit(exp[i])){
            while(isdigit(exp[i]))
                temp+=exp[i++];
            num.push(stoi(temp));
        }
        else{
            if(sign.size()!=0)
                while(sign.size()>0 && toPush(sign.top(),exp[i])==false)
                    num.push(getRes(num,sign));
            sign.push(exp[i]);
            i++;
        }
    }

    while(num.size()!=1)
        num.push(getRes(num,sign));

    return num.top();

}

int main(){
    string exp="2-6-7*8/2+5";
    cout<<exp<<" = "<<calc(exp)<<endl; //expected : -27
    exp="2*3+5/6*3+15";
    cout<<exp<<" = "<<calc(exp)<<endl; //expected : 23.5

}