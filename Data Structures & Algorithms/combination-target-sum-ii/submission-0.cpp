class Solution {
public:
    void helper(vector<int>&candidates,int idx,int target,vector<int>&temp,vector<vector<int>>&ans)
    {
        int n=candidates.size();
         if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(idx==n||target<0)
        return;
       
        for(int i=idx;i<n;i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
            continue;
            temp.push_back(candidates[i]);
            helper(candidates,i+1,target-candidates[i],temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,target,temp,ans);
        return ans;
    }
};
