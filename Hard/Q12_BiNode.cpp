#include<iostream>
using namespace std;

class node{
    public:
        int val;
        node * left;
        node * right;
        node(int val){
            this->val = val;
            left=right=NULL;
        }
};

void TreeToDL(node * root, node * &head){
    if(root==NULL)
        return;
    static node * prev = NULL;
    TreeToDL(root->left, head);
    if(prev==NULL)
        head=root;
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;

    TreeToDL(root->right, head);
}

int main(){

    node * root = new node(5);
    root->left=new node(3);
    root->left->left=new node(2);
    root->left->right=new node(4);
    root->right=new node(7);
    root->right->left=new node(6);
    root->right->right=new node(8);
    node * head;
    TreeToDL(root, head);
    node * temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->right;
    }
    



}