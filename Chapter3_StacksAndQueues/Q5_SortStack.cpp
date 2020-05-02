#include<iostream>
#include<stack>
#include<vector>

using namespace std;
void PrintStack_TopToBottom(stack<int> s) { 
    
    if (s.empty())  
        return; 
    int x = s.top(); 
    s.pop(); 
    cout << x << " ";  
    PrintStack_TopToBottom(s); 
    s.push(x); 

} 
stack<int> sortStack(stack<int> &s){

    stack<int> temp;
    while(!s.empty()){
        int value = s.top();
        s.pop();
        if(temp.empty())
            temp.push(value);
        else{
            while(temp.top()<value){
                int tempVar = temp.top();
                temp.pop();
                s.push(tempVar);
            }
            temp.push(value);
        }
    }
    return temp;
}

int main(){

    stack<int> s;
    vector<int> input = {1,2,3,4,5,6,7,8};
    for(auto i : input)
        s.push(i);

    cout<<"Stack before sorting: "<<endl;
    PrintStack_TopToBottom(s);
    s = sortStack(s);
    cout<<"\nStack After sorting: "<<endl;
    PrintStack_TopToBottom(s);

    


}