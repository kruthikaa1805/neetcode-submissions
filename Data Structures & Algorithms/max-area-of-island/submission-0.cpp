class Solution {
public:
vector<vector<int>>coord={{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(vector<vector<int>>&grid, vector<vector<int>>&visited, int r,int c,int &cnt)
    {
        int n=grid.size();
        int m=grid[0].size();
        visited[r][c]=1;
        cnt++;
        for(int i=0;i<coord.size();i++)
        {
            int x=r+coord[i][0];
            int y=c+coord[i][1];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && !visited[x][y])
            {
               dfs(grid,visited,x,y,cnt);
            }
        }

      return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int cnt=0;
                    dfs(grid,visited,i,j,cnt);
                    maxi=max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};
