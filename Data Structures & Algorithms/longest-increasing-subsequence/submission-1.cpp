class Solution {
public:
    int helper(vector<int>&nums,int idx,int prev_idx,vector<vector<int>>&dp)
    {
        int n=nums.size();
        if(idx==n)
        return 0;
        if(dp[idx][prev_idx+1]!=-1)
        return dp[idx][prev_idx+1];
        int skip=0+helper(nums,idx+1,prev_idx,dp);
        int take=0;
        if(prev_idx==-1 || nums[idx]>nums[prev_idx])
        take=1+helper(nums,idx+1,idx,dp);
        return dp[idx][prev_idx+1]=max(take,skip);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(nums,0,-1,dp);

    }
};
