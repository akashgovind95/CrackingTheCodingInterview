#include<iostream>
#include<vector>
using namespace std;

class MultiStack{
    private:
        int numberOfStack = 3;
        int stackCapacity;
        vector<int> stackCurrSize;
        vector<int> elements;
    public:
        MultiStack(int stackCapacity){
            
            this->stackCapacity = stackCapacity;
            for(int i =0;i<stackCapacity*numberOfStack;i++)
                elements.push_back(-1);
            for(int i = 0;i<numberOfStack;i++)
                stackCurrSize.push_back(-1);
        }
        
        bool isFull(int stackNum){
            //cout<<"StackSize:"<<stackCurrSize[stackNum];
            if(stackCurrSize[stackNum] == (stackCapacity/3) -1)
                return true;
            return false;
        }

        bool isEmpty(int stackNum){
            if(stackCurrSize[stackNum] == -1)
                return true;
            return false;
        }
        
        void push(int stackNum,int value){
            int index =0;
            if(isFull(stackNum))
                cout<<"Stack Full"<<endl;
            else{
                stackCurrSize[stackNum]++;
                index = (stackNum*stackCapacity)/3 + stackCurrSize[stackNum];
                elements[index] = value;
            }
        }

        void pop(int stackNum){
            if (isEmpty(stackNum))
                cout<<"Stack Empty"<<endl;
            else
                stackCurrSize[stackNum]--;
        }

        int top(int stackNum){
            int index = 0;
            if (isEmpty(stackNum))
                return -1;
            else
                index = (stackNum*stackCapacity)/3 + stackCurrSize[stackNum];
            
            return elements[index];
        }

};

int main(){

    MultiStack obj(12);
    obj.push(0,1);  //No OP. Should push successfully
    obj.push(1,2);  //No OP. should push successfully
    obj.push(2,3);  //No Op. should push successfully

    cout<<"Top:"<<obj.top(0)<<endl; //op:1
    cout<<"Top:"<<obj.top(1)<<endl; //op:2
    cout<<"Top:"<<obj.top(2)<<endl; //op:3

    obj.push(0,4); //No OP. Should push successfully
    obj.push(1,5); //No OP. Should push successfully
    obj.push(2,6); //No OP. Should push successfully

    cout<<"Top:"<<obj.top(0)<<endl; //op:4
    cout<<"Top:"<<obj.top(1)<<endl; //op:5
    cout<<"Top:"<<obj.top(2)<<endl; //op:6

    obj.pop(0); //No OP. Should pop successfully
    obj.pop(1); //No OP. Should pop successfully
    obj.pop(2); //No OP. Should pop successfully

    cout<<"Top:"<<obj.top(0)<<endl; //op 1
    cout<<"Top:"<<obj.top(1)<<endl; //op 2
    cout<<"Top:"<<obj.top(2)<<endl; //op 3

    obj.pop(0); //No OP. Should pop successfully
    obj.pop(1); //No OP. Should pop successfully
    obj.pop(2); //No OP. Should pop successfully
    
    cout<<"Top:"<<obj.top(0)<<endl; //op -1
    cout<<"Top:"<<obj.top(1)<<endl; //op -1
    cout<<"Top:"<<obj.top(2)<<endl; //op -1
    
    return 0;

}