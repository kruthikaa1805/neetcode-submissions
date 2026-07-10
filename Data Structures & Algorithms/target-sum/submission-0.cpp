class Solution {
public:
   int helper(vector<int>&nums,int target,int idx,int n)
   {
    if(idx==n)
    {
        if(target==0)
        return 1;
        else
        return 0;
    }
    int add=nums[idx]+helper(nums,target-nums[idx],idx+1,n);
    int sub=-nums[idx]+helper(nums,target+nums[idx],idx+1,n);
    return add+sub;

   }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return helper(nums,target,0,n);
    }
};
