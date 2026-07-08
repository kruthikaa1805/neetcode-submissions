class Solution {
public:
    int helper(vector<int>& nums,int idx,vector<int>&dp)
    {
      int n=nums.size();
      if(idx>=n)
      return 0;
      if(dp[idx]!=-1)
      return dp[idx];
      int pick=nums[idx]+helper(nums,idx+2,dp);
      int dontpick=helper(nums,idx+1,dp);
      return dp[idx]= max(pick,dontpick);
    }
    int rob(vector<int>& nums) {
        int m=nums.size();
        if(m==1)
        return nums[0];
        vector<int>nums1 (nums.begin()+1,nums.end());
        vector<int>nums2 (nums.begin(),nums.end()-1);
        int n=nums1.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int ans1=helper(nums1,0,dp1);
        int ans2=helper(nums2,0,dp2);
        return max(ans1,ans2);

    }
};
