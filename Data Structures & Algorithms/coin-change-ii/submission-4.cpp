class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            dp[0][i]=1;
            else
            dp[0][i]=0;
        }
        for(int i=1;i<n;i++)
        {
            for(int amt=0;amt<=amount;amt++)
            {
                int donttake=dp[i-1][amt];
                int take=0;
                if(amt>=coins[i])
                take=dp[i][amt-coins[i]];
                dp[i][amt]=take+donttake;
            }
        }
        return dp[n-1][amount];
    }
};
