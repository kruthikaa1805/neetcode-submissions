class Solution {
public:
   /* int helper(vector<int>&nums,int idx,int n)
    {
        if(idx>=nums.size()-1)
        {
            return 0;
        }
        int val=nums[idx];
        int mini=INT_MAX;
        int j=idx+val;
        for(int i=idx;i<j;i++)
        {
            int res=helper(nums,i+1,n);
            if(res!=INT_MAX)
          mini=min(mini,1+res);
        }
      return mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
         return helper(nums,0,n);

    }*/
    int jump(vector<int>&nums)
    {
        int n=nums.size();
        int l=0;
        int r=0;
        int jumps=0;
        while(r<n-1)
        {
            int farthest=0;
            for(int i=l;i<=r;i++)
            {
                farthest=max(farthest,i+nums[i]);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};
