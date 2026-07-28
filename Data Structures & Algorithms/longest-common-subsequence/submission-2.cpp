class Solution {
public:
    int cal(int n,int m,string &text1,string &text2,vector<vector<int>> &dp){
        if(n<0)
        return 0;
        if(m<0)
        return 0;
        if (dp[n][m] != -1) return dp[n][m];
        if(text1[n]==text2[m])
        return dp[n][m]=1+cal(n-1,m-1,text1,text2,dp);
        else
         return dp[n][m]=max(cal(n,m-1,text1,text2,dp),cal(n-1,m,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size();
      int m=text2.size();  
      vector<vector<int>> dp(n, vector<int>(m, -1));
      return cal(n-1,m-1,text1,text2,dp);
    }
};
