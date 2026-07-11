class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int best=nums[0];
       int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            best=max(best+nums[i],nums[i]);
            ans=max(ans,best);
        }
        return ans;
    }
};
