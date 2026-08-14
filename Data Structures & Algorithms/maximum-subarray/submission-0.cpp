class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        int i=0;
        int sum=0;
        int ans=INT_MIN;
         while(i<n){
              sum+=nums[i];
              ans=max(ans,sum);
              if(sum<0)
                sum=0;
              
              i++;
              

         }
         return ans;
    }
};
