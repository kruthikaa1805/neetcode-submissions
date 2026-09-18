class Solution {
public:
    
    int helper(vector<int>&nums,int prev_idx,int curr,vector<vector<int>>&dp)
    {
        int n=nums.size();
        if(curr==n)
        return 0;
        int pick=0;
        if(dp[prev_idx+1][curr]!=-1)
        return dp[prev_idx+1][curr];
        if(prev_idx==-1 || nums[prev_idx]<nums[curr])
        {
           pick =1+helper(nums,curr,curr+1,dp);
        }
        int dont=helper(nums,prev_idx,curr+1,dp);
        return dp[prev_idx+1][curr]=max(pick,dont);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return helper(nums,-1,0,dp);
    }
};
