class Solution {
public:
    void helper(vector<int>& nums,int idx,vector<int>&temp,vector<vector<int>> & ans)
    {
        int n=nums.size();
        if(idx==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++)
        {
           
           swap(temp[i],temp[idx]);
           helper(nums,idx+1,temp,ans);
           swap(temp[i],temp[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp=nums;
        helper(nums,0,temp,ans);
        return ans;
    }
};
