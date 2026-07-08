class Solution {
public:
//recursive dp solution
    bool solve(string s,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=j)
        return true;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s[i]==s[j])
        return dp[i][j]=solve(s,i+1,j-1,dp);
    
        return false;

    }
    string longestPalindrome(string s) {
        int n=s.length();
        int max_length=1;
        int start=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
           for(int j=i;j<n;j++)
           {
            if(solve(s,i,j,dp)==true)
            {
                int len=j-i+1;
                if(len>max_length)
                {
                    max_length=len;
                    start=i;
                }
            }
           }
        }
        return s.substr(start,max_length);
    }
};
