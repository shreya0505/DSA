

// 1) Get the Middle of the array and make it root.
// 2) Recursively do same for left half and right half.
//       a) Get the middle of left half and make it left child of the root
//           created in step 1.
//       b) Get the middle of right half and make it right child of the
//           root created in step 1.

#include <bits/stdc++.h>
using namespace std;

class TNode
{
public:
    int data;
    TNode *left;
    TNode *right;
};

TNode *newNode(int data)
{
    TNode *node = new TNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TNode *sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
        return NULL;

    /* Get the middle element and make it root */
    int mid = (start + end) / 2;
    TNode *root = newNode(arr[mid]);

    /* Recursively construct the left subtree  
    and make it left child of root */
    root->left = sortedArrayToBST(arr, start,
                                  mid - 1);

    /* Recursively construct the right subtree  
    and make it right child of root */
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

int main()
{
    return 0;
}