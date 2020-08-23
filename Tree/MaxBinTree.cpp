#include <bits/stdc++.h>
using namespace std;

// Cartesian Tree
// The root is the maximum number in the array.
// The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
// The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
// in-order traversal: we get the array back which we used to create it

//RECURSIVE APPROACH

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *construct(vector<int> &a, int l, int r)
{
    if (l >= r)
        return NULL;
    int mx = INT_MIN, ind;

    for (int i = l; i < r; i++)
    {
        if (a[i] > mx)
        {
            mx = a[i];
            ind = i;
        }
    }
    TreeNode *root = new TreeNode();
    root->val = mx;
    root->left = construct(a, l, ind);
    root->right = construct(a, ind + 1, r);
    return root;
}

TreeNode *constructMaximumBinaryTree(vector<int> &a)
{
    return construct(a, 0, a.size());
}

int main()
{
    return 0;
}