#include <bits/stdc++.h>
using namespace std;

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

// Given a Binary Tree, find size of the Largest Independent Set(LIS) in it.
// A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset.

// SOLUTION
// LISS(X) = MAX { (1 + sum of LISS for all grandchildren of X),
//                      (sum of LISS for all children of X) }

int LISS(Node *root)
{
    if (root == NULL)
        return 0;

    // Calculate size excluding the current node   BASE CONDITION
    int size_excl = LISS(root->left) +
                    LISS(root->right);

    // Calculate size including the current node   HYPOTHESIS
    int size_incl = 1;
    if (root->left)
        size_incl += LISS(root->left->left) +
                     LISS(root->left->right);
    if (root->right)
        size_incl += LISS(root->right->left) +
                     LISS(root->right->right);

    // Return the maximum of two sizes  INDUCTION
    return max(size_incl, size_excl);
}

int main()
{
    return 0;
}