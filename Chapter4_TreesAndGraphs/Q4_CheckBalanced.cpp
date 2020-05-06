#include<iostream>
#include<vector>
#include<algorithm> 
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

        int checkBalanced(TreeNode * node, bool &isBalanced){
            if(node==NULL)
                return 0;
            int leftHeight = 0;
            int rightHeight = 0;    
            if(node->left)
                leftHeight = checkBalanced(node->left, isBalanced);
            if(node->right)
            rightHeight  = checkBalanced(node->left, isBalanced);

            if(abs(leftHeight-rightHeight)>1)
                isBalanced = false;
            return 1 + max(leftHeight,rightHeight);
        }
};

int main(){

    Solution obj;
    vector<int> input = {1,2,3,4,5,6,7,8,9};
    TreeNode * root = obj.createTree(input,0,input.size()-1); 
    bool isBalanced = true;
    obj.checkBalanced(root,isBalanced); //OP: 1
    cout<<"Is Balaned? Ans: "<<isBalanced;
}