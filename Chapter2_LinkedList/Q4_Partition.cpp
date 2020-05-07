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
        pair<ListNode*, ListNode*> partitionList(ListNode * &head, int key){
            if(head==NULL){
                cout<<"Head is NULL"<<endl;
                return make_pair(head,head);
            }

            ListNode * lessThanKey_head = NULL;
            ListNode * lessThanKey_tail = NULL;

            ListNode * moreThanKey_head = NULL;
            ListNode * moreThanKey_tail = NULL;
            ListNode * p = head;
            while(p){
                if(p->val < key){
                    if(lessThanKey_head == NULL )
                        lessThanKey_head=lessThanKey_tail=p;
                    else{
                       lessThanKey_tail->next=p;
                       lessThanKey_tail=lessThanKey_tail->next;
                    }
                }
                else{
                    if(moreThanKey_head == NULL )
                        moreThanKey_head=moreThanKey_tail=p;
                    else{
                       moreThanKey_tail->next=p;
                       moreThanKey_tail=moreThanKey_tail->next;
                    }
                }
                p=p->next;
            }
            
            lessThanKey_tail->next = moreThanKey_head;
            moreThanKey_tail->next=NULL;
            return make_pair(lessThanKey_head,moreThanKey_tail);

        }
};


int main(){
    solution obj;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    pair<ListNode*, ListNode*> headTailpair;

    obj.insert(head,tail,1);
    obj.insert(head,tail,6);
    obj.insert(head,tail,2);
    obj.insert(head,tail,7);
    obj.insert(head,tail,3);
    obj.insert(head,tail,8);
    obj.insert(head,tail,4);
    obj.insert(head,tail,9);
    obj.insert(head,tail,5);
    obj.insert(head,tail,10);
    cout<<"Before partition"<<endl;
    obj.printList(head);
    
    headTailpair = obj.partitionList(head,5);
    
    head = headTailpair.first;
    tail = headTailpair.second;
    
    cout<<"After partition"<<endl;
    obj.printList(head);
    return 0;
}