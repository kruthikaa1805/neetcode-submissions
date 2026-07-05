class Solution {
public:
    void helper(vector<int>& nums,int idx,vector<int>&temp,vector<vector<int>>& ans)
    {
        int n=nums.size();
       ans.push_back(temp);
        for(int i=idx;i<n;i++)
        {
            if(i>idx && nums[i]==nums[i-1])
            continue;
            temp.push_back(nums[i]);
            helper(nums,i+1,temp,ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        helper(nums,0,temp,ans);
        return ans;
    }
};
