class Solution {
public:
    void helper(vector<int>&nums,int idx,int n,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(idx==n)
        {
             ans.push_back(nums);
             return;
        }
        for(int i=idx;i<n;i++)
        {
            swap(nums[i],nums[idx]);
            helper(nums,idx+1,n,temp,ans);
            swap(nums[i],nums[idx]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        helper(nums,0,n,temp,ans);
        return ans;
    }
};
