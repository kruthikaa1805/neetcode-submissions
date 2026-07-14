class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
          sum+=nums[i];
        }
        int act_sum= (n*(n+1))/2;
        return act_sum-sum;*/
        int n=nums.size();
        int m=0;
        for(int i=0;i<=n;i++)
        {
          m=m^i;
        }
        for(int i=0;i<n;i++)
        {
            m=m^nums[i];
        }
        return m;
    }
};
