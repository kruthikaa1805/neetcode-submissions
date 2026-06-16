class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*set<vector<int>>temp;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum==0)
                    temp.insert({nums[i],nums[j],nums[k]});
                    else
                    continue;

                }
            }
        }
        vector<vector<int>>ans(temp.begin(),temp.end());
        return ans;*/
        vector<vector<int>>temp;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    temp.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                   while(j<k && nums[k]==nums[k+1])
                   k--;
                   while(j<k && nums[j-1]==nums[j])
                    j++;
                }
                else if(sum>0)
                k--;
                else if(sum<0)
                j++;
            }
                
        }
        
        return temp;
    }
};
