#include <bits/stdc++.h>
using namespace std;


//  SLIDING WINDOW / TWO POINTER Approach
//  Linear Time
int lengthOfLongestSubstring(string s)
{
    //l stores index at which last the character last occured
    int l[256];
    memset(l, -1, sizeof(l));
    int len, mlen = INT_MIN;
    int n = s.size();
    if (!n)
        return 0;
    //Start of Window
    int i = 0;

    //Loop for end of window
    for (int j = 0; j < n; j++)
    {
        int c = (int)(s[j]);
        // if window start beyond last occured index, char is not present in current window
        if (i > l[c])
            l[c] = -1;

        //If character is persent in current window, move the start of the window to last occurrence+1
        if (l[c] != -1)
            i = l[c] + 1;

        //Update last occurrence
        l[c] = j;

        //Calculate and update max length
        len = (j - i + 1);

        mlen = max(len, mlen);
    }

    return mlen;
}

int main()
{
    return 0;
}