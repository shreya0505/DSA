#include <bits/stdc++.h>
using namespace std;


//Time complexity o(n2)
string longestPalindrome(string s) {
  
    int n=s.size();
        if(!s.size()) return "";
    
    bool dp[n][n]; //dp[i][j] stores if substring i to j is palindrome or not
    pair<int,int> sub; //stores start and size of ans
    memset(dp, 0,sizeof(dp));
        
        //Check for len=1
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        sub={0,1};

        //Check for len=2
        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                sub={i,2};
            }
    
        //Bottom up approach
        //check from len k=3 to n for all i=0 to n
        for(int k=3;k<=n;k++){
            for(int i=0;i+k<=n;i++){
                int j= i+k-1;
                dp[i][j]= (dp[i+1][j-1] && s[i]==s[j]);
                if(dp[i][j]==1){
                    //save start and size of longest palindrome
                    sub={i,k};
                }
            }
        }
        //copy to new string
        string ans = s.substr(sub.first, sub.second);
        return ans;
  
    }



int main()
{
    return 0;
}