class Solution {
public:
    int helper(vector<int>&prices,int n,int idx,bool flag,vector<vector<int>>&dp)
    {
        if(idx>=n)
        return 0;
        if(dp[idx][flag]!=-1)
        return dp[idx][flag];
        if(flag==0)
        {
            int buy=-prices[idx]+helper(prices,n,idx+1,1,dp);
            int dontbuy=helper(prices,n,idx+1,0,dp);
            return dp[idx][flag]=max(buy,dontbuy);

        }
        else if(flag==1)
        {
            int sell=prices[idx]+helper(prices,n,idx+2,0,dp);
            int dontsell=helper(prices,n,idx+1,1,dp);
            return dp[idx][flag]=max(sell,dontsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        bool flag=0;
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(prices,n,0,0,dp);
    }
};
