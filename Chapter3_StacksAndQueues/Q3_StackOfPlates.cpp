#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class MultiStack{
    private:
    vector<stack<int>> mainStack;
    int threshold;

    public:
    
    MultiStack(int threshold){
        
        this->threshold = threshold;
    }

    void push(int value){
        if(mainStack.size()==0 || mainStack[mainStack.size()-1].size()==threshold ){
            stack<int> temp;
            mainStack.push_back(temp);
        }
        mainStack[mainStack.size()-1].push(value);
        
    }

    void pop(){
        if(mainStack.size()!=0){
            mainStack[mainStack.size()-1].pop();
            if(mainStack[mainStack.size()-1].size()==0)
                mainStack.pop_back();
        }
        else
            cout<<"Stack Empty"<<endl;
    }
    int top(){
        if(mainStack.size()!=0)
            return mainStack[mainStack.size()-1].top();
        return -1;

    }

};

int main(){

    MultiStack obj(1);

    obj.push(1);
    cout<<"TOP:"<<obj.top()<<endl; //OP: 1
    obj.push(2);
    cout<<"TOP:"<<obj.top()<<endl; //OP: 2
    obj.push(3);
    cout<<"TOP:"<<obj.top()<<endl; //OP: 3
    obj.push(4);
    cout<<"TOP:"<<obj.top()<<endl; //OP: 4
    obj.push(5);
    cout<<"TOP:"<<obj.top()<<endl; //OP: 5

    obj.pop();
    cout<<"TOP:"<<obj.top()<<endl; //OP: 4
    obj.pop();
    cout<<"TOP:"<<obj.top()<<endl; //OP: 3
    obj.pop();
    cout<<"TOP:"<<obj.top()<<endl; //OP: 2
    obj.pop();
    cout<<"TOP:"<<obj.top()<<endl; //OP: 1
    obj.pop();
    cout<<"TOP:"<<obj.top()<<endl; //OP: -1
    obj.pop();                     //OP: Stack Empty 
    cout<<"TOP:"<<obj.top()<<endl; //OP -1

}