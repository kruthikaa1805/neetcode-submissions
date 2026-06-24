class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
        /*unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1)
            return nums[i];
        }
        return -1;*/
        int slow=nums[0];
        int fast=nums[nums[0]];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
         slow=0;
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
