class Solution {
public:
    /*bool helper(vector<int>&nums,int idx)
    {
        if(idx>=nums.size()-1)
        return true;
        if(nums[idx]==0)
        return false;
        int val=nums[idx];
        for(int i=1;i<=val;i++)
        {
            if(helper(nums,idx+i)==true)
            return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
        return true;
        if(nums[0]==0)
        return false;
         return helper(nums,0);

    }*/
    bool canJump(vector<int>& nums)
    {
        int n=nums.size();
        int max_reach=nums[0];
        for(int i=1;i<n;i++)
        {
            if(i>max_reach)
            return false;
            int  curr_reach=i+nums[i];
            max_reach=max(max_reach,curr_reach);
        }
        return true;
    }
};
