#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    public:
        int val;
        TreeNode * left;
        TreeNode * right;

        TreeNode(int data){
            val = data;
            left=NULL;
            right=NULL;
        }

};

class Solution{
    public:
        TreeNode * createTree(vector<int> & arr, int start, int end){
            
            if(start<=end){
                int mid = (start+end)/2;
                TreeNode* temp = new TreeNode(arr[mid]);
                temp->left = createTree(arr,start,mid-1);
                
                temp->right = createTree(arr,mid+1,end);
                return temp;
            }
            return NULL;
        }

        void printInorder(TreeNode * node){

            if(!node)
                return;
            printInorder(node->left);
            cout<<node->val<<" ";
            printInorder(node->right);
        }

        int lowestCommonAncestor(TreeNode * node, int num1, int  num2){
            if(node==NULL)
                return 0;
            if(node->val == num1 || node->val == num2)
                return node->val;

            int leftVal = lowestCommonAncestor(node->left,num1,num2);
            int rightVal = lowestCommonAncestor(node->right,num1,num2);

            if(leftVal && rightVal)
                return node->val;
            if(!leftVal)
                return rightVal;
            return leftVal;
            
        }
};

int main(){

    Solution obj;
    vector<int> input = {1,2,3,4,5,6,7,8,9};
    TreeNode * root = obj.createTree(input,0,input.size()-1); 
    cout<<obj.lowestCommonAncestor(root, 1,4)<<endl;
    cout<<obj.lowestCommonAncestor(root, 8,9)<<endl;

}