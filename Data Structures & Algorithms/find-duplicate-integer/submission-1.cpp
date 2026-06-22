class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       /* int arr[9]={0};
        for(int i=0;i<nums.size();i++)
        {
            arr[nums[i]]++;
            if(arr[nums[i]]>1)
            return nums[i];
        }
        return -1;*/
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1)
            return nums[i];
        }
        return -1;
    }
};
