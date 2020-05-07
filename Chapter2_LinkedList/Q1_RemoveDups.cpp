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
                

            ListNode * p = head;
            while(p){
                cout<<p->val<<"->";
                p=p->next;
            }
            cout<<"NULL"<<endl;

        }
        void removeDups(ListNode * &head){
            if(head==NULL || head->next==NULL)
                return;
            ListNode * p = head;
            while(p!=NULL && p->next!=NULL){
                ListNode * q = p->next;
                while(q!=NULL && q->val==p->val)q=q->next;
                p->next=q;
                p=p->next;
            }

            ListNode * q = head;    
            while(q){
                cout<<q->val<<"->";
                q=q->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main(){
    solution obj;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    obj.insert(head,tail,1);
    obj.insert(head,tail,1);
    obj.insert(head,tail,2);
    obj.insert(head,tail,2);
    obj.insert(head,tail,2);
    obj.insert(head,tail,3);
    obj.insert(head,tail,4);
    obj.insert(head,tail,5);
    obj.insert(head,tail,5);
    obj.insert(head,tail,5);
    obj.removeDups(head); 

    return 0;
}