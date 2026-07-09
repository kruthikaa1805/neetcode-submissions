class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //optimized kadane's
        int n=nums.size();
        if(n==1)
        return nums[0];
        int maxi=nums[0];
        int mini=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            int val=nums[i];
            int oldie=maxi;
            maxi=max(val,max(val*maxi,val*mini));
            mini=min(val,min(mini*val,oldie*val));
            ans=max(ans,maxi);
        }
        return ans;
    }
};
