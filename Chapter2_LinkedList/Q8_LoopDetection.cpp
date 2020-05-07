#include<iostream>
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

        ListNode * loopDetection(ListNode * &head){
            ListNode * fast = head;
            ListNode * slow = head;

            bool loop = false;
            while(fast && fast->next){
                fast=fast->next->next;
                slow=slow->next;
                if(fast==slow){
                    loop =true;
                    break;
                }
            }
            if(loop){
                fast=head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
            return NULL;
        }

        
};

int main(){
    solution obj;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    ListNode * rep = new ListNode(3);
    ListNode * loopNode = NULL;

    obj.insert(head,tail,1);
    obj.insert(head,tail,2);
    tail->next = rep;
    tail=tail->next;
    obj.insert(head,tail,3);
    obj.insert(head,tail,4);
    tail->next= rep;
    loopNode = obj.loopDetection(head);
    cout<<"Case 1:"<<endl;
    if(loopNode)
        cout<<"loop at: "<<loopNode->val<<endl;
    else
        cout<<"No loop"<<endl;



    head = NULL;
    tail = NULL;
    
    obj.insert(head,tail,1);
    obj.insert(head,tail,2);
    obj.insert(head,tail,3);
    obj.insert(head,tail,4);
    loopNode = obj.loopDetection(head);
    cout<<"Case 2:"<<endl;
    if(loopNode)
        cout<<"loop at: "<<loopNode->val<<endl;
    else
        cout<<"No loop"<<endl;
    return 0;
}