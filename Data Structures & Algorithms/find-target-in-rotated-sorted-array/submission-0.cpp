class Solution {
public:
    int findmin(vector<int>&nums)
    {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]>nums[end])
            start=mid+1;
            else if(nums[mid]<=nums[end])
            end=mid;
        }
        return start;

    }
    int bs(int i,int j,vector<int>&nums,int target)
    {
        int start=i;
        int end=j;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]<target)
            start=mid+1;
            else
            end=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int min_idx=findmin(nums);
        int a=bs(0,min_idx-1,nums,target);
        int b=bs(min_idx,n-1,nums,target);
        if(a!=-1)
        return a;
        else if(b!=-1)
        return b;
        return -1;
    }
};
