#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child  */

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};



//INORDER : LEFT---ROOT---RIGHT
void inorderUtil(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;

    inorderUtil(root->left, res);

    res.push_back(root->data);

    inorderUtil(root->right, res);
}

vector<int> inOrder(struct Node *root)
{
    vector<int> res;
    inorderUtil(root, res);
    return res;
}

//PREORDER : ROOT LEFT RIGHT
void preorderUtil (Node *root, vector <int> &res)
{
    if (root == NULL)return;
    
    res.push_back (root->data);
    
    preorderUtil(root->left, res);
    
    preorderUtil(root->right, res);
}



vector <int> preorder(Node* root)
{
   vector <int> res;
   preorderUtil (root, res);
   return res;
}


//POST ORDER : LEFT RIGHT ROOT
void postorderUtil( Node *root, vector<int>&res ){
    if (root == NULL)return;
    
    preorderUtil(root->left, res);
    
    preorderUtil(root->right, res);
    
    res.push_back (root->data);
    
}

vector <int> postOrder(Node* root)
{

  vector<int> res;
  postorderUtil(root, res);
  return res;
}


int main()
{
    return 0;
}