class Solution {
public:
    vector<vector<int>>dp;
    int cal(vector<int>& nums, int target,int sum,int n,int offset){
        
        if(n<0)
        return sum==target;
        if(dp[n][sum+offset]!=-1)
        return dp[n][sum+offset];
        int add=cal(nums,target,sum+nums[n],n-1,offset);
        int sub=cal(nums,target,sum-nums[n],n-1,offset);    
        return dp[n][sum+offset]=add+sub;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        long long len=0;
        for(int i=0;i<n;i++){
            len+=nums[i];
        }
        long long offset=len;
        dp.assign(n,vector<int>(2*len+1,-1));
      return cal(nums,target,0,n-1,offset); 
    }
};
