class Solution {
public:
    int helper(int ind,vector<int>&coins,int target,vector<vector<int>>&dp)
    {
        if(target==0)
        return 1;
        if(ind ==0)
        {
            if(target%coins[ind]==0)
            return 1;
            return 0;
        }
        if(dp[ind][target]!=-1)
        return dp[ind][target];
        int take=0;
        if(target>=coins[ind])
        take=helper(ind,coins,target-coins[ind],dp);
        int skip=helper(ind-1,coins,target,dp);
        return dp[ind][target]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(n-1,coins,amount,dp);
    }
};
