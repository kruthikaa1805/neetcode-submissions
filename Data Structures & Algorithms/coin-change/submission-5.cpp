class Solution {
public:
    int helper(int ind,vector<int>& coins,int amount)
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
        int pick=1e8;
        if(amount>=coins[ind])
        pick=helper(ind,coins,amount-coins[ind])+1;
        
        int move=helper(ind-1,coins,amount);
        return min(pick,move);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        if(amount==0)
        return 0;
        if(amount<coins[0])
        return -1;
        int n=coins.size();
        int ans= helper(n-1,coins,amount);
        if(ans==1e8)
        return -1;
        return ans;
    }
};
