#include<iostream>
#include<vector>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648

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

        bool validateBST(TreeNode * node, int max, int min){
            if(node==NULL)
                return true;
            if(node->val > min && node->val < max)
                return validateBST(node->left,node->val,min) && validateBST(node->right,max,node->val);
            return false;
        }
};

int main(){

    Solution obj;
    vector<int> input = {1,2,3,4,5,6,7,8,9};
    TreeNode * root = obj.createTree(input,0,input.size()-1); 
    cout<<"Is BST? Ans: "<<obj.validateBST(root,INT_MAX,INT_MIN); //OP: 1
}