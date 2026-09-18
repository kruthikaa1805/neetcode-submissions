class Solution {
public:
    vector<vector<int>>coords={{-1,0},{1,0},{0,1},{0,-1}};
    int helper(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        if(i<0 || i>=n && j<0 || j>=m)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int maxi=0;
        for(int k=0;k<coords.size();k++)
        {
            int new_x=i+coords[k][0];
            int new_y=j+coords[k][1];
            if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && matrix[i][j]<matrix[new_x][new_y])
            {
                maxi=max(maxi,1+helper(matrix,new_x,new_y,dp));
            }
        }
        return dp[i][j]=maxi;
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
        return ans+1;
    }
};
