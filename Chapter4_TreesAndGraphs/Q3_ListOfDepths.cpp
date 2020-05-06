#include<iostream>
#include<vector>
#include<queue>
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

struct ListNode{
    public:
        int val;
        ListNode * next;

        ListNode(int data){
            val = data;
            next=NULL;
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


        vector<ListNode *> levelOrderTraversal(TreeNode * node){
            vector<ListNode*> headList;
            if(!node)
                return headList;
            queue<TreeNode*> q;
            q.push(node);

            while(!q.empty()){
                int size = q.size();
                ListNode * head = NULL;
                ListNode * tail = NULL;
                for(int i =0;i<size;i++){
                    TreeNode * tempTreeNode = q.front();
                    q.pop();
                    if(tempTreeNode->left)
                        q.push(tempTreeNode->left);
                    if(tempTreeNode->right)
                        q.push(tempTreeNode->right);
        
                    ListNode * tempListNode = new ListNode(tempTreeNode->val);
                    if(head==NULL){
                        head=tempListNode;
                        tail=tempListNode;
                    }
                    else{
                        tail->next=tempListNode;
                        tail=tail->next;
                    }
                }
                headList.push_back(head);
            }  
            return headList;
        }

        void printLevelOrderTraversal(vector<ListNode*> headList){
            int depth = 0;
            for(auto head : headList){
                ListNode * temp = head;
                cout<<"Depth "<<depth<<": ";
                depth++;
                while(temp!=NULL){
                    cout<<temp->val<<" ";
                    temp=temp->next; 
                }        
                cout<<endl;  
            }
        }
};

int main(){

    Solution obj;
    vector<int> input = {1,2,3,4,5,6,7,8,9};
    TreeNode * root = obj.createTree(input,0,input.size()-1); 
    vector<ListNode*> headList;
    headList = obj.levelOrderTraversal(root);
    obj.printLevelOrderTraversal(headList);   

}