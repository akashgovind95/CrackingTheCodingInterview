#include <iostream> 
#include<unordered_map>
#include<algorithm>

using namespace std; 

class TreeNode { 
  
    public:
        int val; 
        TreeNode *left, *right;


        TreeNode(int data){
            val = data;
            left=NULL;
            right=NULL;
        } 


}; 

class solution{
    public:
        TreeNode* Insert(TreeNode *root, int value) 
        { 
            if(!root)  
                return new TreeNode(value);
            if(value > root->val) 
                root->right = Insert(root->right, value); 
            else
                root->left = Insert(root->left, value);
            return root; 
        } 

        void CountPathsWithSum(TreeNode * node, unordered_map<int,int> &sumCount, int sumSoFar, int &pathCount ,int &key){
            if(node==NULL)
                return;
            sumSoFar+=node->val;
            pathCount+=sumCount[sumSoFar-key];
            sumCount[sumSoFar]++;
            CountPathsWithSum(node->left,sumCount,sumSoFar,pathCount,key);
            CountPathsWithSum(node->right,sumCount,sumSoFar,pathCount,key);
            sumCount[sumSoFar]--;
        }

};

int main() 
{ 
    TreeNode *root = NULL; 
    solution obj;
    unordered_map<int,int> sumCount;
    int key  = 5;
    int pathCount = 0;

    root = obj.Insert(root, 4); //4, 2, 1, 3, 5, 6
    obj.Insert(root, 2);
    obj.Insert(root, 1);
    obj.Insert(root, 3);
    obj.Insert(root, 5);
    obj.Insert(root, 6);
    
    obj.CountPathsWithSum(root,sumCount,0,pathCount,key);

    cout<<pathCount;
    
    return 0; 
}