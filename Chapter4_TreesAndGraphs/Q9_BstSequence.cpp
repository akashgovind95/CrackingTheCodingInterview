#include <iostream> 
#include<vector>
#include<queue>
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

        vector<vector<int> > findAllSeq(TreeNode *ptr)
        {
            if (ptr == NULL) {
                vector<int> seq;
                vector<vector<int> > v;
                v.push_back(seq);
                return v;
            }


            if (ptr -> left == NULL && ptr -> right == NULL) {
                vector<int> seq;
                seq.push_back(ptr -> val);
                vector<vector<int> > v;
                v.push_back(seq);
                return v;
            }

            vector<vector<int> > results, left, right;
            left  = findAllSeq(ptr -> left);
            right = findAllSeq(ptr -> right);
            int size = left[0].size() + right[0].size() + 1;

            vector<bool> flags(left[0].size(), 0);
            for (int k = 0; k < right[0].size(); k++)
                flags.push_back(1);

            for (int i = 0; i < left.size(); i++) {
                for (int j = 0; j < right.size(); j++) {
                    do {
                        vector<int> tmp(size);
                        tmp[0] = ptr -> val;
                        int l = 0, r = 0;
                        for (int k = 0; k < flags.size(); k++) {
                            tmp[k+1] = (flags[k]) ? right[j][r++] : left[i][l++];
                        }
                        results.push_back(tmp);
                    } while (next_permutation(flags.begin(), flags.end()));
                }
            }

            return results;
        }

                


};

int main() 
{ 
    TreeNode *root = NULL; 
    solution obj;
    root = obj.Insert(root, 4); //4, 2, 1, 3, 5, 6
    obj.Insert(root, 2);
    obj.Insert(root, 1);
    obj.Insert(root, 3);
    obj.Insert(root, 5);
    obj.Insert(root, 6);
    vector<vector<int>> result = obj.findAllSeq(root);
    for(auto i : result){
        cout<<endl;
        for(auto j : i)
            cout<<j<<" ";
    }
    return 0; 
}