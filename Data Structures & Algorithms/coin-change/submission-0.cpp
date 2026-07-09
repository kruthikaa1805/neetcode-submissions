class Solution {
public:
    int helper(vector<int>&coins,int target,int idx)
    {
        if(idx==0)
        {
            if(target%coins[idx]==0)
            return target/coins[0];

            return 1e9;
        }
        if(target==0)
        {
            return 0;
        }
       
        int dontpick=helper(coins,target,idx-1);
        int pick=INT_MAX;
        if(target>=coins[idx])
        {
            pick=1+helper(coins,target-coins[idx],idx);
        }
        return min(pick,dontpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        int ans= helper(coins,amount,n-1);
        if(ans>=1e9)
        return -1;
        return ans;
    }
};
