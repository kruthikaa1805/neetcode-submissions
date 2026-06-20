class Solution {
public:
    int findMin(vector<int> &nums) {
        //wherever min index is, that is the answer
        int n=nums.size();

        int start=0;
        int end=n-1;
        int ans=0;
        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]>nums[end])
            {
                start=mid+1;
            }
            else if(nums[mid]<=nums[end])
            {
            end=mid;
            }
        }
        return nums[start];
    }
};
