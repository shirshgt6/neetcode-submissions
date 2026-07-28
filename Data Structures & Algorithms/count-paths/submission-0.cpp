class Solution {
public:
    int cal(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m&&j==n)
        return 1;
        if(i>m||j>n)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];

    
        return dp[i][j]=cal(i,j+1,m,n,dp)+cal(i+1,j,m,n,dp);
    }
    int uniquePaths(int m, int n) {
      int i=0;
      int j=0 ;
      vector<vector<int>>dp(m,vector<int>(n,-1));
      return cal(i,j,m-1,n-1,dp);
      
    }
};
