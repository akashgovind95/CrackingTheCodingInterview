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
};

int main(){

    Solution obj;
    vector<int> input = {1,2,3,4,5,6,7,8,9};
    TreeNode * root = obj.createTree(input,0,input.size()-1); 
    obj.printInorder(root); //OP: 1 2 3 4 5 6 7 8 9
}