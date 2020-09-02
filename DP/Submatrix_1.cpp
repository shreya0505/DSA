    #include <bits/stdc++.h>
    using namespace std;

    //https://leetcode.com/problems/count-square-submatrices-with-all-ones/
    
    int countSquares(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int dp[n][m]; //No of square submatrix ending at i,j
        int c=0;  
        memset(dp, 0, sizeof(dp)); 

        //account for first row anc col
        for(int i=0;i<n;i++){
            dp[i][0]= g[i][0];
            c+=dp[i][0]; 
        }
        for(int j=0;j<m;j++){
            dp[0][j]=g[0][j];
            c+=dp[0][j]; 
        }
        
        if(g[0][0])
            c--;


        for(int i=1; i<n;i++){
            for(int j=1; j<m; j++){
                // Only if top left, top and left are 1's it can be a square submatrix of 2*2 ending at i,j
                // Min of top, left, top left count will give the biggest one ending at i,j
                if(g[i][j]){
                  dp[i][j]= 1+ min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                
                }
                else {
                    dp[i][j]=0;
                }
                 c+=dp[i][j];   
            }
        }
      return c;  
    }

    int main()
    {
        return 0;
    }