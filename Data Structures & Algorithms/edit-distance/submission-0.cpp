class Solution {
public:
    int helper(string &word1,string &word2,int i,int j,vector<vector<int>>&dp)
    {
        int n=word1.length();
        int m=word2.length();
        if(i>=n)
        return m-j;
        if( j>=m)
        { 
            return n-i;
        }
       if(dp[i][j]!=-1)
       return dp[i][j];
        
        if(word1[i]==word2[j])
        return dp[i][j]=helper(word1,word2,i+1,j+1,dp);
        else
        {
        int ins=1+helper(word1,word2,i,j+1,dp);
        int d=1+helper(word1,word2,i+1,j,dp);
        int r=1+helper(word1,word2,i+1,j+1,dp);
        return dp[i][j]=min({ins,d,r});
        }

    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(word1,word2,0,0,dp);
    }
};
