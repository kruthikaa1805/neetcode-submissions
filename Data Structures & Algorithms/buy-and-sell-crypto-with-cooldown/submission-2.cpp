class Solution {
public:
    int helper(vector<int>&prices,int ind,bool flag,vector<vector<int>>&dp)
    {
        int n=prices.size();
        if(ind>=n)
        return 0;
        if(dp[ind][flag]!=-1)
        return dp[ind][flag];
        if(flag==1)
        {
            int buy=helper(prices,ind+1,0,dp)-prices[ind];
            int dont=helper(prices,ind+1,1,dp);
            return dp[ind][flag]=max(buy,dont);
        }
        else
        {
            int sell=prices[ind]+helper(prices,ind+2,1,dp);
            int dont=helper(prices,ind+1,0,dp);
            return dp[ind][flag]=max(sell,dont);
        }
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
        return 0;
        //flag=>buy=1,sell=0
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(prices,0,1,dp);
    }
};
