class Solution {
public:
    int helper(string s,string t ,int i,int j,vector<vector<int>>&dp)
    {
        int n=s.length();
        int m=t.length();
        if(i==n && j<m)
        return 0;
        if(i<=n && j==m)
        return 1;
        if(i>n)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
       int pick=0;
        if(s[i]==t[j])
        {
             pick= helper(s,t,i+1,j+1,dp);
        }
        int left=helper(s,t,i+1,j,dp);
        return dp[i][j]=left+pick;
    }
    int numDistinct(string s, string t) {
        if(t.length()>s.length())
        return 0;
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
         return helper(s,t,0,0,dp);
    }
};
