class Solution {
public:
    bool helper(vector<int>&nums,int target,int idx,vector<vector<int>>&dp)
    {
        int n=nums.size();
        if(target<0)
        return false;
        if(target==0)
        return true;
        if(idx==n)
        return false;
        if(dp[idx][target]!=-1)
        return dp[idx][target];
        bool pick=false;
        if(target>=nums[idx])
        {
          pick=helper(nums,target-nums[idx],idx+1,dp);
        }
        bool dontpick=helper(nums,target,idx+1,dp);
        return dp[idx][target]=pick||dontpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1)
        return false;
        else
        {
          
            int target=sum/2;
             vector<vector<int>>dp(n,vector<int>(target+1,-1));
           return helper(nums,target,0,dp);
        }
    }
};
