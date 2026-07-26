class Solution {
public:
    void helper(vector<int>&nums,int idx,int target,vector<int>&temp,vector<vector<int>>&ans,int n)
    {
        
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(idx==n|| target<0)
        return;
        //skip and move ;//take and stay
        helper(nums,idx+1,target,temp,ans,n);
        temp.push_back(nums[idx]);
        helper(nums,idx,target-nums[idx],temp,ans,n);
        temp.pop_back();
       
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        helper(nums,0,target,temp,ans,n);
        return ans;
    }
};
