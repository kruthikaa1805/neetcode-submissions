class Solution {
public:
    int helper(string &s,int ind,int n,vector<int>&dp)
    {
        if(ind==n)
        return 1;
        if(dp[ind]!=-1)
        return dp[ind];
        if(s[ind]=='0')
        return dp[ind]=0;
        int ways=helper(s,ind+1,n,dp);
        if(ind+1<n)
        {
            int twodigs=(s[ind]-'0')*10+s[ind+1]-'0';
            if(twodigs<=26)
            ways+=helper(s,ind+2,n,dp);
        }
        return dp[ind]=ways;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return helper(s,0,n,dp);
    }
};
