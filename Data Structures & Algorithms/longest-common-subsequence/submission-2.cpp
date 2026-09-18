class Solution {
public:
     int helper(string &text1,string &text2,int ind1,int ind2,int n,int m,vector<vector<int>>&dp)
     {
        if(ind1==n || ind2==m)
        return 0;
        if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2])
        {
            return dp[ind1][ind2]=1+helper(text1,text2,ind1+1,ind2+1,n,m,dp);
        }
        int left=helper(text1,text2,ind1+1,ind2,n,m,dp);
        int right=helper(text1,text2,ind1,ind2+1,n,m,dp);
        return dp[ind1][ind2]=max(left,right);
     }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(text1,text2,0,0,n,m,dp);
    }
};
