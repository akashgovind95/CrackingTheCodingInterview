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

        void printList(ListNode * &head){
            ListNode * p = head;
            while(p){
                cout<<p->val<<"->";
                p=p->next;
            }
            cout<<"NULL"<<endl;
        }
        void delMiddleNode(ListNode * &head){
            if(head==NULL){
                cout<<"Head is NULL"<<endl;
                return;
            }
            ListNode * p = head;
            ListNode * q = head;
            while(q && q->next){p=p->next; q=q->next->next;}
            p->val = p->next->val;
            p->next = p->next->next;
        }
};


int main(){
    solution obj;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    obj.insert(head,tail,1);
    obj.insert(head,tail,2);
    obj.insert(head,tail,3);
    obj.insert(head,tail,4);
    obj.insert(head,tail,5);
    obj.insert(head,tail,6);
    obj.insert(head,tail,7);
    obj.insert(head,tail,8);
    obj.insert(head,tail,9);

    cout<<"Before deleting middle node"<<endl;
    obj.printList(head);
    obj.delMiddleNode(head);
    cout<<"After deleting middle node"<<endl;
    obj.printList(head);
    return 0;
}