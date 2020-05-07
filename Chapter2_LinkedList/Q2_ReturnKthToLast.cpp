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
        ListNode * kthToLast(ListNode * &head, int k){
            if(head==NULL){
                cout<<"Head is NULL"<<endl;
                return head;
            }
            ListNode * p = head;
            ListNode * q = head;

            while(q && k--)q=q->next;

            if(q==NULL && k>0){
                cout<<"K > size of linked list"<<endl;
                return NULL;
            }
            while(q){
                q=q->next;
                p=p->next;
            }
            return p;
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
    obj.insert(head,tail,10);
    obj.printList(head);
    int k = 5;
    ListNode * Kth = obj.kthToLast(head, k);
    if(Kth)
        cout<<k<<"th term from last: "<<Kth->val<<endl;
    return 0;
}