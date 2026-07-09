class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int ans=INT_MIN;
       for(int i=0;i<n;i++)
       {
        dp[i][i]=nums[i];
        ans=max(ans,dp[i][i]);
       }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i!=j)
                {
            dp[i][j]=nums[j]*dp[i][j-1];
               ans=max(ans,dp[i][j]);
                }
               
            }
        }
        return ans;
    }
};
