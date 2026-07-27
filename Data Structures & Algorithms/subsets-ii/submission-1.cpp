class Solution {
public:
    void helper(vector<int>&nums,int idx,vector<int>&temp,set<vector<int>>&st)
    {
        if(idx==nums.size())
        {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        helper(nums,idx+1,temp,st);
        temp.pop_back();
        helper(nums,idx+1,temp,st);
        return;

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        vector<int>temp;
        helper(nums,0,temp,st);
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
