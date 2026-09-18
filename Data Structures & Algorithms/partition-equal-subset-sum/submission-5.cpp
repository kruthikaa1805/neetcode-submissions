class Solution {
public:
    bool helper(vector<int>&nums,int ind,int target,vector<vector<int>>&dp)
    {
        if(target<0)
        return false;
        if(target==0)
        return true;
        if(ind==0)
        {
            if(target==nums[ind])
            return true;
            return false;
        }
        if(dp[ind][target]!=-1)
        return dp[ind][target];
        bool pick=false;
        if(target>=nums[ind])
        pick=helper(nums,ind-1,target-nums[ind],dp);
        bool dont=helper(nums,ind-1,target,dp);
        return dp[ind][target]=pick||dont;


    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
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
            return helper(nums,n-1,target,dp);
        }
    }
};
