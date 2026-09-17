class Solution {
public:
    int helper(int ind,vector<int>&cost,vector<int>&dp)
    {
        if(ind>=cost.size())
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int opt1=helper(ind+1,cost,dp);
        int opt2=helper(ind+2,cost,dp);
        return dp[ind]=min(opt1,opt2)+cost[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
       int ans1=helper(0,cost,dp);
       int ans2=helper(1,cost,dp);
       return min(ans1,ans2);
    }
};
