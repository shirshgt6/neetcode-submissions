class Solution {
public:
    vector<vector<int>>dp;
    int cal(string &word1,string &word2,int n,int m){
        if(n<0)
        return m+1;
        if(m<0)
        return n+1;
        if(dp[n][m]!=-1)
        return dp[n][m];
        if(word1[n]==word2[m])
        return dp[n][m]=cal(word1,word2,n-1,m-1);
        else {
            int ins=1+cal(word1,word2,n,m-1);
            int dlt=1+cal(word1,word2,n-1,m);
            int rep=1+cal(word1,word2,n-1,m-1);
            return dp[n][m]=min({ins,dlt,rep});
        }

    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return cal(word1,word2,n-1,m-1);
    }
};
