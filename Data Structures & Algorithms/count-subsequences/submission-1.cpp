class Solution {
public:
    vector<vector<int>>dp;
    
    int cal(string &s,string &t,int n,int m){
        if(m<0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n][m]!=-1)
        return dp[n][m];
        if(s[n]==t[m]){
         return dp[n][m]=  cal(s,t,n-1,m-1)+
            cal(s,t,n-1,m);
        }
        else if(s[n]!=t[m]){
          return dp[n][m]= cal(s,t,n-1,m);
        }

    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return cal(s,t,n-1,m-1);
        
    }
};
