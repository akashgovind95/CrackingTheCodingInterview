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

    int topAtIndex(int idx){
        if(idx<=mainStack.size())
            return mainStack[idx].top();
        return -1;
    }

    int removeAndReturnBottomValue(stack<int> &s){
        stack<int> temp;
        int bottomValue = -1;
        while(!s.empty()){

            temp.push(s.top());
            s.pop();
        }
        bottomValue = temp.top();
        temp.pop();
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        return bottomValue;
    }

    void popAtIndex(int idx){
        if(idx>=mainStack.size() || idx<0 )
            cout<<"Index out of bounds";
        else if(idx == mainStack.size()-1)
            mainStack[mainStack.size()-1].pop();
        else{
            mainStack[idx].pop();
            for(int i=idx;i<mainStack.size()-1;i++){
                mainStack[i].push(removeAndReturnBottomValue(mainStack[i+1]));
            }
        }
    }

    

};

int main(){
    
    MultiStack obj1(1);

    obj1.push(1);
    obj1.push(2);
    obj1.push(3);
    obj1.push(4);
    obj1.push(5);
    cout<<"TOP:"<<obj1.topAtIndex(0)<<endl; //OP: 1
    cout<<"TOP:"<<obj1.topAtIndex(1)<<endl; //OP: 2
    cout<<"TOP:"<<obj1.topAtIndex(2)<<endl; //OP: 3
    cout<<"TOP:"<<obj1.topAtIndex(3)<<endl; //OP: 4
    cout<<"TOP:"<<obj1.topAtIndex(4)<<endl; //OP: 5
    obj1.popAtIndex(1);
    cout<<"TOP:"<<obj1.topAtIndex(0)<<endl; //OP: 1
    cout<<"TOP:"<<obj1.topAtIndex(1)<<endl; //OP: 3
    cout<<"TOP:"<<obj1.topAtIndex(2)<<endl; //OP: 4
    cout<<"TOP:"<<obj1.topAtIndex(3)<<endl; //OP: 5


}