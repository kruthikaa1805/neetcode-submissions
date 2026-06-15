class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            int val=nums[i];
            if(mp.find(val-1)!=mp.end())
            {
                continue;
            }
            else
            {
                int cnt=1;
                while(mp.find(val+1)!=mp.end())
                {
                    cnt++;
                    val=val+1;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};
