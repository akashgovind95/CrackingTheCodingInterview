#include<iostream>
#include<stack>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode * next;
    ListNode(int val){this->val = val;next=NULL;}

};

class solution{
    public:

        void insert(ListNode * &head, ListNode * &tail, int key){
            ListNode * temp = new ListNode(key);
            if(head==NULL){
                tail=temp;
                head=temp;
            }
                
            else{
                tail->next=temp;
                tail=tail->next;
            }
        }

        void printList(ListNode * &head){
            ListNode * p = head;
            while(p){
                cout<<p->val<<"->";
                p=p->next;
            }
            cout<<"NULL"<<endl;
        }
        

        bool checkPalindrome(ListNode * head){

            if(head==NULL)
                return true; //empty list is palindrome
            
            ListNode * middle = head;
            ListNode * q = head;
            stack<int> s;

            while(q && q->next){
                s.push(middle->val); //pushing every element until we reach the end including middle.
                middle=middle->next; 
                q=q->next->next; 
            }

            if(middle->val == s.top()) //incase of even elements the middle will point to the second middle node. 
                s.pop();               // If second middle is equal to the first middle that is stack.top() then we pop from stack
            
            middle=middle->next;
                
            while(middle!=NULL){
                if(middle->val != s.top())
                    return false;
                s.pop();
                middle=middle->next;
            }

            return true;

        }
};


int main(){
    solution obj;

    ListNode* head = NULL;
    ListNode* tail = NULL;
    
    //Case 1
    obj.insert(head,tail,1);
    obj.insert(head,tail,2);
    obj.insert(head,tail,3);
    obj.insert(head,tail,4);
    obj.insert(head,tail,5);
    obj.insert(head,tail,4);
    obj.insert(head,tail,3);
    obj.insert(head,tail,2);
    obj.insert(head,tail,1);
    cout<<"Case 1: ";
    obj.printList(head);
    cout<<"Is Palindrome? Ans: "<<obj.checkPalindrome(head)<<endl;


    //Case 2
    head=NULL;
    tail=NULL;
    obj.insert(head,tail,1);
    obj.insert(head,tail,2);
    obj.insert(head,tail,3);
    obj.insert(head,tail,4);
    obj.insert(head,tail,5);
    obj.insert(head,tail,5);
    obj.insert(head,tail,4);
    obj.insert(head,tail,3);
    obj.insert(head,tail,2);
    obj.insert(head,tail,1);
    cout<<"Case 2: ";
    obj.printList(head);
    cout<<"Is Palindrome? Ans: "<<obj.checkPalindrome(head)<<endl;
    
    //Case 3
    head=NULL;
    tail=NULL;
    obj.insert(head,tail,1);
    obj.insert(head,tail,2);
    obj.insert(head,tail,3);
    obj.insert(head,tail,4);
    obj.insert(head,tail,5);
    obj.insert(head,tail,6);
    obj.insert(head,tail,7);
    obj.insert(head,tail,8);
    obj.insert(head,tail,9);
    obj.insert(head,tail,10);
    cout<<"Case 3: ";
    obj.printList(head);
    cout<<"Is Palindrome? Ans: "<<obj.checkPalindrome(head)<<endl;
    return 0;
}