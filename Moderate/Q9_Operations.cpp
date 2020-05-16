#include<iostream>
using namespace std;

int getNegate(int a){
    int x = a<0?1:-1;
    int neg = 0;
    while(a!=0){ a+=x; neg+=x; }
    return neg;
}

int add(int a, int b){
    return a+b;
}

int divide(int a, int b){
    if(a==0)
        return 0;
    if(b==0)
        return 0;
    int absa = abs(a);
    int absb = abs(b);
    int i = 1, sum = absb;
    while(absa>sum){i++,sum+=absb;}
    if(sum>absa)
        i--;
    if(a <0 && b<0)
        return i;
    if(a<0 || b<0)
        return getNegate(i);
    return i;
}

int multiply(int a, int b){
    if( b>a)
        return multiply(b,a);
    int res = 0;
    int absa = abs(a);
    int absb = abs(b);
    for(int i=1;i<=absb;i++)
        res+=absa;
    
    if(a<0 && b<0)
        return res;
    if(a<0 || b<0)
        return getNegate(res);
    return res;

}

int subtract(int a, int b){
    return a+getNegate(b);
}


int main(){
    int a=10,b=5;
    cout<<"a: "<<a<<" b: "<<b<<endl;
    cout<<a<<"+"<<b<<"= "<<add(a,b)<<endl;
    cout<<a<<"-"<<b<<"= "<<subtract(a,b)<<endl;
    cout<<a<<"*"<<b<<"= "<<multiply(a,b)<<endl;
    cout<<a<<"/"<<b<<"= "<<divide(a,b)<<endl;
}

