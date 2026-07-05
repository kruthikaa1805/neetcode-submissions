class Solution {
public:
    void helper(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,map<vector<int>,int>&mp)
    {
        int n=nums.size();
        if(i==n)
        {
            if(mp.find(temp)==mp.end())
            {
                mp[temp]=1;
                ans.push_back(temp);
            }
            return;   
        }
        temp.push_back(nums[i]);
        helper(i+1,nums,ans,temp,mp);
        temp.pop_back();
         helper(i+1,nums,ans,temp,mp);
       
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        map<vector<int>,int> mp;
        helper(0,nums,ans,temp,mp);
        return ans;
    }
};
