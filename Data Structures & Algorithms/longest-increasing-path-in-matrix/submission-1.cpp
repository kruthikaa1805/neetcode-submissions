class Solution {
public:
    vector<vector<int>>coords={{-1,0},{1,0},{0,-1},{0,1}};
    int helper(vector<vector<int>>& matrix,int r,int c,vector<vector<int>>&dp)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        if(r<0 || c<0|| r>=n || c>=m)
        return 0;
        if(dp[r][c]!=-1)
        return dp[r][c];
        int maxi=0;
        for(int i=0;i<coords.size();i++)
        {
            int x=r+coords[i][0];
            int y=c+coords[i][1];
            int len=1;
            if(x>=0 && y>=0 && x<n && y<m && matrix[x][y]>matrix[r][c])
            len=1+helper(matrix,x,y,dp);
            maxi=max(maxi,len);
        }
        return dp[r][c]=maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,helper(matrix,i,j,dp));
            }
        }
        return ans;
    }
};
