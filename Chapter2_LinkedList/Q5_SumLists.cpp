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

        pair<ListNode *, ListNode *> sumOfList(ListNode * head1, ListNode * head2){
            
            ListNode * p = head1;
            ListNode * q = head2;

            ListNode * sumListHead = NULL;
            ListNode * sumListTail = NULL;

            int carry = 0;
            while(p || q){
                int sum = 0;
                if(p)
                    sum+=p->val;
                if(q)
                    sum+=q->val;
                sum+=carry;
                carry = 0;
                if(sum>9){
                    carry = 1;
                    sum=sum%10;
                }
                ListNode * temp = new ListNode(sum);
                if(sumListHead==NULL)
                    sumListHead=sumListTail=temp;
                else{
                    sumListTail->next = temp;
                    sumListTail=sumListTail->next;
                }
                p=p->next;
                q=q->next;
            }

            if(carry==1){
                ListNode * temp = new ListNode(carry);
                sumListTail->next = temp;
                sumListTail=sumListTail->next;
            }

            return make_pair(sumListHead,sumListTail);


        }
        
};

int main(){
    solution obj;
    ListNode* head1 = NULL;
    ListNode* tail1 = NULL;
    ListNode* head2 = NULL;
    ListNode* tail2 = NULL;
    ListNode* sumListHead = NULL;
    ListNode* sumListTail = NULL;
    pair<ListNode *, ListNode *> sumHeadTail;

    obj.insert(head1,tail1,7);
    obj.insert(head1,tail1,1);
    obj.insert(head1,tail1,6);
    cout<<"List 1: ";
    obj.printList(head1);

    obj.insert(head2,tail2,5);
    obj.insert(head2,tail2,9);
    obj.insert(head2,tail2,6);
    cout<<"List 2: ";
    obj.printList(head2);
    
    sumHeadTail = obj.sumOfList(head1,head2);
    sumListHead = sumHeadTail.first;
    sumListTail = sumHeadTail.second;
    cout<<"Sum of List 1 and List 2: ";
    obj.printList(sumListHead);
    return 0;
}