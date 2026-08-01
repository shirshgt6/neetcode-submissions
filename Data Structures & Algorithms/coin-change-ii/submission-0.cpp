class Solution {
public:
    vector<vector<int>>dp;
    int cal(int sum,int amount ,vector<int>&coins,int n,int &res){
        if(sum==amount){
         return 1;
        }
        if(n<0||sum>amount)
        return 0;
        if(dp[n][sum]!=-1)
        return dp[n][sum];
       int take= cal(sum+coins[n],amount,coins,n,res);
       int nottake= cal(sum,amount,coins,n-1,res);
       return dp[n][sum]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {      
        int n=coins.size();
        int res=0;
        dp.assign(n,vector<int>(amount+1,-1));
       return cal(0,amount,coins,n-1,res);
        
    }
};
