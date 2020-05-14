#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode*left,*right;
        TreeNode(int val){
            this->val = val;
            left=NULL;
            right=NULL;
        }
};

class RankGenerator{
    public:
        vector<int> arr;
        TreeNode * root=NULL;
        unordered_map<int,TreeNode*> m;

        bool search(TreeNode * root, int val){
            if(root==NULL)
                return false;
            if(root->val==val)
                return true;
            return search(root->left,val) || search(root->right,val);
                
        }
 
        
        TreeNode * insert(TreeNode * root, int val){
            if(root==NULL)
                return new TreeNode(val);
            if(root->val>val)
                root->left = insert(root->left,val);
            else
                root->right = insert(root->right,val);
            return root;
                
        }

        void getNewNumber(int x){
            arr.push_back(x);
            if(search(root,x)==false)
                root = insert(root,x);
        }

        int getRankHelper(TreeNode * root, int val){
            
            if(root==NULL)
                return 0;
            //cout<<root->val<<" ";
            int rank = getRankHelper(root->left,val) + getRankHelper(root->right,val);
            if(root->val<val)
                return 1+rank;
            return rank; 
        }

        int getRank(int x){
            if(search(root,x))
                return getRankHelper(root,x);
            return -1;
        }

};

int main(){
    RankGenerator obj;

    for(int i = 5;i>0;i--)
        obj.getNewNumber(i);
    for(int i = 6;i<11;i++)
        obj.getNewNumber(i);
    
    cout<<obj.getRank(5)<<endl;
    cout<<obj.getRank(8)<<endl;
    cout<<obj.getRank(3)<<endl;
    cout<<obj.getRank(9)<<endl;
    cout<<obj.getRank(6)<<endl;
    cout<<obj.getRank(1)<<endl;
    cout<<obj.getRank(10)<<endl;
    cout<<obj.getRank(11)<<endl;
}
