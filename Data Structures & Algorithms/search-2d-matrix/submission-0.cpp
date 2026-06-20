class Solution {
public:
    bool bs(vector<int>&nums,int target)
    {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            return true;
            else if(nums[mid]<target)
            start=mid+1;
            else
            end=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0;i<rows;i++)
        {
            if(target>=matrix[i][0] && target<=matrix[i][cols-1])
            return bs(matrix[i],target);
        }
        return false;
    }
};
