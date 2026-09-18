class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp_max(n);
        vector<int>dp_min(n);
        dp_max[0]=nums[0];
        dp_min[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
          dp_max[i]=max({dp_max[i-1]*nums[i],nums[i],dp_min[i-1]*nums[i]});
          dp_min[i]=min({dp_max[i-1]*nums[i],nums[i],dp_min[i-1]*nums[i]});
          ans=max(ans,dp_max[i]);
        }
        return ans;
        
    }
};
