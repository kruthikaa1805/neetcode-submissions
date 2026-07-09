class Solution {
public:
    int helper(string &s,int idx,vector<int>&dp)
   {
    int n=s.length();
       if(idx==n)
       {
        return 1;
       }
       if(dp[idx]!=-1)
       return dp[idx];
       if(s[idx]=='0')
       return dp[idx]=0;
       int ways=helper(s,idx+1,dp);
       if(idx+1<n)
       {
          int two_digit=(s[idx]-'0')*10+ s[idx+1]-'0';
       if(two_digit<=26)
       ways+=helper(s,idx+2,dp);
       }
       
       return dp[idx]=ways;
   }
    int numDecodings(string s) {
        int n=s.length();
        if(n==0 || s[0]=='0')
        return 0;
        vector<int>dp(n,-1);
        return helper(s,0,dp);
    }
};
