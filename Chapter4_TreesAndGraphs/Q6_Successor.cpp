#include <iostream> 
#include<vector>
#include<queue>

using namespace std; 

class TreeNode { 
  
    public:
        int val; 
        TreeNode *left, *right, *parent;


        TreeNode(int data){
            val = data;
            left=NULL;
            right=NULL;
            parent=NULL;
        } 

        TreeNode(int data, TreeNode * par){
            val = data;
            left=NULL;
            right=NULL;
            parent=par;
        } 

}; 

class solution{
    public:
        TreeNode* Insert(TreeNode *root, TreeNode * parent, int value) 
        { 
            if(!root)  
                return new TreeNode(value,parent); 
            if(value > root->val) 
                root->right = Insert(root->right, root, value); 
            else
                root->left = Insert(root->left, root, value);
            return root; 
        } 


        TreeNode* search(TreeNode* root, int key) 
        { 

            if (root == NULL || root->val == key) 
            return root; 
            if (root->val < key) 
            return search(root->right, key); 
            return search(root->left, key); 
        } 

        TreeNode* getMin(TreeNode * node ){
            TreeNode * temp = node;
            while(temp->left)
                temp=temp->left;
            return temp;
        }

        TreeNode * nextInorderSuccessor(TreeNode * root, int value){

            TreeNode * key = search(root,value);
            if(key==NULL)
                return NULL;
            if(key->right!=NULL)
                return getMin(key->right);
            
            TreeNode * parent = key->parent;
            while(parent!=NULL && key==parent->right){
                key=parent;
                parent=key->parent;
            }
            return parent;
            
                 

        }


};
  

int main() 
{ 
    TreeNode *root = NULL; 
    solution obj;
    root = obj.Insert(root, NULL, 10);
    obj.Insert(root, NULL, 5);
    obj.Insert(root, NULL, 2);
    obj.Insert(root, NULL, 4);
    obj.Insert(root, NULL, 15);
    obj.Insert(root, NULL, 12);
    obj.Insert(root, NULL, 17);  
    cout<<"Successor of 12: "<<obj.nextInorderSuccessor(root,12)->val<<endl;
    cout<<"Successor of 2: "<<obj.nextInorderSuccessor(root,2)->val<<endl;
    cout<<"Successor of 4: "<<obj.nextInorderSuccessor(root,4)->val<<endl;
    return 0; 
}