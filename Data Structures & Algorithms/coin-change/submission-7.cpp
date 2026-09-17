class Solution {
public:
    int helper(int ind,vector<int>& coins,int amount,vector<vector<int>>&dp)
    {
        if(amount==0)
        return 0;
        if(ind<0)
        return 1e8;
        if(ind==0)
        {
            if(amount%coins[0]==0)
            return amount/coins[0];
            return 1e8;
        }
        if(dp[ind][amount]!=-1)
        return dp[ind][amount];
        int pick=1e8;
        if(amount>=coins[ind])
        pick=helper(ind,coins,amount-coins[ind],dp)+1;
        
        int move=helper(ind-1,coins,amount,dp);
        return dp[ind][amount]=min(pick,move);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        if(amount==0)
        return 0;
        if(amount<coins[0])
        return -1;
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= helper(n-1,coins,amount,dp);
        if(ans==1e8)
        return -1;
        return ans;
    }
};
