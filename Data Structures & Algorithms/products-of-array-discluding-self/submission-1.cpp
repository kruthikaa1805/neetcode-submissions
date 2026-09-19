class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n=nums.size();
           vector<int>pre(n);
           vector<int>suff(n);
           int ans=1;
           for(int i=0;i<n;i++)
           {
            pre[i]=ans;
            ans*=nums[i];
            
           }
           int res=1;
           for(int i=n-1;i>=0;i--)
           {
             suff[i]=res;
            res*=nums[i];
           
           }
           for(int i=0;i<n;i++)
           {
            pre[i]*=suff[i];
           }
           return pre;
    }
};
