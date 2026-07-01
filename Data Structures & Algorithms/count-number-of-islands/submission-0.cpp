class Solution {
public:
vector<vector<int>>coord={{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int r,int c)
    {
        int n=grid.size();
        int m=grid[0].size();
     visited[r][c]=1;
     for(int i=0;i<coord.size();i++ )
     {
        int x=r+coord[i][0];
        int y=c+coord[i][1];
        if(x>=0 && x<n &&y>=0 && y<m && !visited[x][y] && grid[x][y]=='1')
        {
            dfs(grid,visited,x,y);
        }
     }
     return;

    }
    int numIslands(vector<vector<char>>& grid) {
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
                    cnt++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return cnt;
    }
};
