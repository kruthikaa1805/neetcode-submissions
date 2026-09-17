class Solution {
public:
     int helper(int ind,vector<int>&nums,vector<int>&dp)
    {
        if(ind>=nums.size())
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int pick=helper(ind+2,nums,dp)+nums[ind];
        int dont=helper(ind+1,nums,dp);
        return dp[ind]= max(pick,dont);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        vector<int>dp(n-1,-1);
        vector<int>dp2(n-1,-1);
        vector<int>temp1 (nums.begin()+1,nums.end());
        vector<int>temp2 (nums.begin(),nums.end()-1);
        int ans1=helper(0,temp1,dp);
        int ans2=helper(0,temp2,dp2);
        return max(ans1,ans2);

    }
};
