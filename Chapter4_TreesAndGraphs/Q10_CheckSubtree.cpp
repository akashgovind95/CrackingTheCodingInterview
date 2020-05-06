#include <iostream> 
#include<vector>
#include<queue>
#include<algorithm>

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

};

bool matchTree(TreeNode * t1,TreeNode * t2){
    if(t1==NULL && t2==NULL)
        return true;
    if(t1==NULL || t2==NULL)
        return false;
    if(t1->val!=t2->val)
        return false;
    return matchTree(t1->left,t2->left) && matchTree(t1->right,t2->right);
}

bool subtree(TreeNode * t1,TreeNode * t2){
    if(t1==NULL)
        return false;
    if(matchTree(t1,t2))
        return true;
    return subtree(t1->left,t2) || subtree(t1->right,t2);

}

bool checkSubtree(TreeNode * t1,TreeNode * t2){
    if(t2==NULL)
        return true;
    return subtree(t1,t2);

}

int main() 
{ 
    TreeNode *root1 = NULL; 
    solution obj1;
    root1 = obj1.Insert(root1, NULL, 4); 
    obj1.Insert(root1, NULL, 2);
    obj1.Insert(root1, NULL, 1);
    obj1.Insert(root1, NULL, 3);
    obj1.Insert(root1, NULL, 5);
    obj1.Insert(root1, NULL, 6);
    obj1.Insert(root1, NULL, 7);

    //Case 1
    TreeNode *root2 = NULL; 
    solution obj2;
    root2 = obj2.Insert(root2, NULL, 5); 
    obj2.Insert(root2, NULL, 7);
    obj2.Insert(root2, NULL, 8);

    cout<<"Case 1: "<<checkSubtree(root1,root2)<<endl;

    //Case 2
    TreeNode *root3 = NULL; 
    solution obj3;
    root3 = obj3.Insert(root3, NULL, 5); 
    obj3.Insert(root3, NULL, 6);
    obj3.Insert(root3, NULL, 7);

    cout<<"Case 2: "<<checkSubtree(root1,root3)<<endl;
    return 0; 
}