#include<iostream>
#include<unordered_map>
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

        ListNode * getIntersectionUsingMap(ListNode * &head1, ListNode * &head2){
            if(head1==NULL || head2==NULL)
                return NULL;
            unordered_map<ListNode*,int> m;
            ListNode * p = head1;
            ListNode * q = head2;

            while(p){
                m[p]=1;
                p=p->next;
            }
            while(q){
                if(m[q]==1)
                    return q;
                q=q->next;
            }
            return NULL;
        }

        ListNode * getIntersectionWithoutUsingMap(ListNode * &head1, ListNode * &head2){
            if(head1==NULL || head2==NULL)
                return NULL;
            ListNode * p = head1;
            ListNode * q = head2;
            int size1 = 0;
            int size2 = 0;

            while(p){
                p=p->next;
                size1++;
            }
            while(q){
                q=q->next;
                size2++;
            }
            p=head1;
            q=head2;
            int diff = abs(size1-size2);
            if(size1>size2)
                while(diff--)p=p->next;
            else
                while(diff--)q=q->next;
            
            while(q && p){
                if(p==q)
                    return p;
                p=p->next;
                q=q->next;
            }
            return NULL;


        }

        
        
};

int main(){
    solution obj;
    ListNode* head1 = NULL;
    ListNode* tail1 = NULL;
    ListNode* head2 = NULL;
    ListNode* tail2 = NULL;
    ListNode* commonListHead = NULL;
    ListNode* commonListTail = NULL;

    obj.insert(commonListHead,commonListTail,8);
    obj.insert(commonListHead,commonListTail,9);
    obj.insert(commonListHead,commonListTail,10);

    obj.insert(head1,tail1,1);
    obj.insert(head1,tail1,2);
    obj.insert(head1,tail1,3);
    tail1->next = commonListHead;
    cout<<"List 1: ";
    obj.printList(head1);

    obj.insert(head2,tail2,4);
    obj.insert(head2,tail2,5);
    obj.insert(head2,tail2,6);
    obj.insert(head2,tail2,7);
    tail2->next = commonListHead;
    cout<<"List 2: ";
    obj.printList(head2);


    cout<<endl<<"Finding intersection with map"<<endl;
    ListNode * intersection = obj.getIntersectionUsingMap(head2,head1);
    if(intersection)
        cout<<"Intersection at: "<<intersection->val;
    else
        cout<<"No intersection";

    cout<<endl<<"Finding intersection without map"<<endl;
    intersection = obj.getIntersectionWithoutUsingMap(head1,head2);
    if(intersection)
        cout<<"Intersection at: "<<intersection->val;
    else
        cout<<"No intersection";

    return 0;
}