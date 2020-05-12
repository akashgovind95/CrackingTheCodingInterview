#include<iostream>
#include<stack>
using namespace std;

void TOH(int N, string from, string to, string aux){
   if(N==1){
       cout<<"Moving Disc 1 form rod "<<from<<" to rod "<<to<<endl;
       return;
   }
   TOH(N-1,from,aux,to);
   cout<<"Moving Disc "<<N<<" form rod "<<from<<" to rod "<<to<<endl;
   TOH(N-1,aux,to,from);


    
}

int main(){
    TOH(4,"A","C","B");
}