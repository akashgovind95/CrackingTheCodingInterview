#include<iostream>
#include<stack>
using namespace std;

class myQueue{
    private:
        stack<int> s1;
        stack<int> s2;

    public:

        void PrintStack(stack<int> s) { 
            if (s.empty())  
                return; 
            int x = s.top(); 
            s.pop(); 
            PrintStack(s); 
            cout << x << " ";  
            s.push(x); 

        } 
        void stackCopy(stack<int> &src, stack<int> &dest){
            while(!src.empty()){
                dest.push(src.top());
                src.pop();
            }
            
            //cout<<endl;
        }
        void push(int value){
            if(s1.empty()){
                stackCopy(s2,s1);
                s2.push(value);
                stackCopy(s1,s2);
                //PrintStack(s2);
            }
            else{
                stackCopy(s1,s2);
                s1.push(value);
                stackCopy(s2,s1);
                //PrintStack(s1);
            }
        }
        void pop(){
            if(s1.empty() && s2.empty())
                cout<<"Empty Queue";
            else if(s1.empty()){
                s2.pop();
                //PrintStack(s2);
                //cout<<endl;
            }
            else{
                s1.pop();
                //PrintStack(s1);
                //cout<<endl;
            }
            
        }
        int top(){
            if(s1.empty() && s2.empty()){
                cout<<"Empty Queue";
                return -1;
            }
            else if(s1.empty())
                return s2.top();
            else
                return s1.top();
        }

};

int main(){
    myQueue obj;

    obj.push(1);  // Queue : 1
    obj.push(2); // Queue : 2  1
    obj.push(3); // Queue : 3 2 1
    obj.push(4); // Queue : 4 3 2 1 
    obj.push(5); // Queue : 5 4 3 2 1
    obj.pop(); //Queue 5 4 3 2
    cout<<"TOP:"<<obj.top()<<endl;  //OP: 2
    obj.pop(); // Queue 5 4 3
    cout<<"TOP:"<<obj.top()<<endl; // OP 3
    obj.pop(); //Queue 5 4
    cout<<"TOP:"<<obj.top()<<endl; //OP r
}