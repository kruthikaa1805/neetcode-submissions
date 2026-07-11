class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
       int n=nums.size();
        int i=0;
        while(i<n && nums[i]!=val)
        {
            i++;
        }
        if(i==n)
        return i;

        int j=i;
        while(j<n && nums[j]==val)
        j++;
        if(j==n)
        return i;
        while(j<n)
        {
            nums[i]=nums[j];
            i++;
            j++;
        }
        return i;
    }
};