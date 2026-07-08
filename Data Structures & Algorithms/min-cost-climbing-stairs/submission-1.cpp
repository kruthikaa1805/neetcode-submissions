class Solution {
public:
     int helper(vector<int>&cost,int idx,vector<int>&dp)
    {
        int n=cost.size();
       if(idx>=n)
       return 0;
       if(dp[idx]!=-1)
       return dp[idx];
        return dp[idx]=cost[idx]+min(helper(cost,idx+1,dp),helper(cost,idx+2,dp));

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        int price=min(helper(cost,0,dp),helper(cost,1,dp)) ;
         return price;
    }
};
