#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int data; 
    int children; 
    Node *left, *right; 
}; 
  
Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    temp->children = 0; 
    return temp; 
} 

int getElements(Node* root) 
{ 
    if (!root) 
        return 0; 
    return getElements(root->left) + 
          getElements(root->right) + 1; 
} 
  

void insertChildrenCount(Node*& root) 
{ 
    if (!root) 
        return; 
  
    root->children = getElements(root) - 1; 
    insertChildrenCount(root->left); 
    insertChildrenCount(root->right); 
} 
int children(Node* root) 
{ 
    if (!root) 
        return 0; 
    return root->children + 1; 
} 

int randomNodeUtil(Node* root, int count) 
{ 
    if (!root) 
        return 0; 
    if (count == children(root->left)) 
        return root->data; 
    if (count < children(root->left)) 
        return randomNodeUtil(root->left, count); 
    return randomNodeUtil(root->right, 
              count - children(root->left) - 1); 
} 

int randomNode(Node* root) 
{ 
    srand(time(0)); 
  
    int count = rand() % (root->children + 1); 
    return randomNodeUtil(root, count); 
} 
  
int main() 
{ 

    Node* root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
    root->left->right = newNode(40); 
    root->left->right = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  
    insertChildrenCount(root); 
  
    cout << "A Random Node From Tree : "
         << randomNode(root) << endl; 
  
    return 0; 
} 