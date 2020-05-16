#include<iostream>
using namespace std;
void swap(int &a, int &b){

    a=a+b;
    b=a-b;
    a=a-b;
}

int main(){
    int a =10;
    int b = 20;
    cout<<"Before Swap: "<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    swap(a,b);
    cout<<"After Swap: "<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;

}