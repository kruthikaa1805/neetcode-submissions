class Solution {
public:
    int helper(vector<int>&nums,int ind,int target,map<pair<int,int>,int>&dp)
    {
        int n=nums.size();
        if(ind ==n && target==0)
        return 1;
        if(ind==n )
        return 0;
        if(dp.find({ind,target})!=dp.end())
        return dp[{ind,target}];
        int add=helper(nums,ind+1,target-nums[ind],dp);
        int sub=helper(nums,ind+1,target+nums[ind],dp);
        return dp[{ind,target}]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
       // vector<vector<int>>dp(n,vector<int>(target+1,-1));
        map<pair<int,int>,int>dp;
        return helper(nums,0,target,dp);
    }
};
