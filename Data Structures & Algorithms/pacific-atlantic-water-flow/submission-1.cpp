class Solution {
public:
    vector<vector<int>>coords={{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(int r,int c,vector<vector<int>>&heights,vector<vector<int>>&visited)
    {
        int n=heights.size();
        int m=heights[0].size();
        visited[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int x=r+coords[i][0];
            int y=c+coords[i][1];
            if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && heights[x][y]>=heights[r][c])
            {
                dfs(x,y,heights,visited);
            }
        }
        return;

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        vector<vector<int>>pacific(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        dfs(0,j,heights,pacific);
        for(int i=0;i<n;i++)
       dfs(i,0,heights,pacific);
        for(int i=0;i<n;i++)
        dfs(i,m-1,heights,atlantic);
        for(int j=0;j<m;j++)
        dfs(n-1,j,heights,atlantic);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j]==1 && atlantic[i][j]==1)
                ans.push_back({i,j});

            }
        }
        return ans;
        
    }
};
