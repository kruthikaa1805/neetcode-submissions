class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        // vector<int>dp_max(n);
        // vector<int>dp_min(n);
        // dp_max[0]=nums[0];
        // dp_min[0]=nums[0];
        int maxi=nums[0];
        int mini=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            int temp=maxi;
          maxi=max({temp*nums[i],nums[i],mini*nums[i]});
          mini=min({temp*nums[i],nums[i],mini*nums[i]});
          ans=max(ans,maxi);
        }
        return ans;
        
    }
};
