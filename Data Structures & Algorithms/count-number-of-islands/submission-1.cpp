class Solution {
public:
    vector<vector<int>>coords={{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(int r,int c,vector<vector<char>>&grid,vector<vector<int>>&visited)
    {
        visited[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<coords.size();i++)
        {
            int x=r+coords[i][0];
            int y=c+coords[i][1];
            if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]=='1')
            dfs(x,y,grid,visited);

        }
        return;

    }
    int numIslands(vector<vector<char>>& grid) {
        //just find the number of disconnected 1 groups.
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    dfs(i,j,grid,visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
