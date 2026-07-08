class Solution {
public:
     int helper(vector<int>&nums,int idx,vector<int>&dp)
     {
        int n=nums.size();
        if(idx>=n)
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        int pick=nums[idx]+helper(nums,idx+2,dp);
        int dontpick=helper(nums,idx+1,dp);
        return dp[idx]=max(pick,dontpick);
     }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(nums,0,dp);

    }
};
