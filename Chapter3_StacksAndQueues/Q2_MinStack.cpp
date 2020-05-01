#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack {
public:
   
    stack<int> minStack;
    stack<int> s;
    MinStack() {}
    
    void push(int x) {
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
        s.push(x);
    }
    
    void pop() {
       if (s.top() == minStack.top()) 
            minStack.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

int main()
{
    MinStack* obj = new MinStack();
    vector<string> command = {"push","push","push","getMin","top","pop","getMin"};
    vector <vector<int>> value= {{-2},{0},{-1},{},{},{},{}};
    vector<int> res;
    
    for(int i = 0;i<command.size();i++){
        if(command[i] == "push")
            obj->push(value[i][0]);        
        else if(command[i] == "pop")
            obj->pop();
        else if(command[i] == "getMin")
            res.push_back(obj->getMin());
        else
            res.push_back(obj->top());
    }
    
    
    for(auto i : res)
        cout<<i<<" ";
    return 0;
}