#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==0) return -1;
        if(amount ==0) return 0;
        
        int dp[amount+1];
        dp[0] = 0; 
        
        for (int i=1; i<=amount; i++) 
            dp[i] = INT_MAX;
        
        for (int i=1; i<=amount; i++) 
        {    
            // Go through all coins smaller than i 
            for (int j=0; j<coins.size(); j++) 
              if (coins[j] <= i) 
              { 
                  int sub_res = dp[i-coins[j]]; 
                  if (sub_res != INT_MAX && sub_res + 1 < dp[i]) 
                      dp[i] = sub_res + 1; 
              } 
        }
         if(dp[amount]==INT_MAX)
             return -1;
        else return dp[amount];
    }

int main()
{
    return 0;
}