#include <bits/stdc++.h>
using namespace std;

// Slow pointer : one step
// Fast pointer : two steps

// Time:O(n) Space:O(1)
// Number of iterations for both pointers to reach the cycle= non-cyclic length = N
// Number of iterations for pointers to meet = cyclic length = K

// List has no cycle:
// The fast pointer reaches the end first

// List has cycle:
// The fast and slow pointer meet

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if (!head || !head->next)
        return false;

    ListNode *slow = head;
    ListNode *fast = head;

    while (slow != fast)
    {
        if (!fast || !fast->next)
            return false;

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

int main()
{
    return 0;
}