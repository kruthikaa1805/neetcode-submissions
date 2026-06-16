class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>temp;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum==0)
                    temp.insert({nums[i],nums[j],nums[k]});
                    else
                    continue;

                }
            }
        }
        vector<vector<int>>ans(temp.begin(),temp.end());
        return ans;
    }
};
