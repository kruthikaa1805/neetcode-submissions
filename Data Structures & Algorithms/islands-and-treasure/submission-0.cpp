class Solution {
public:
    vector<vector<int>>coord={{-1,0},{1,0},{0,-1},{0,1}};
    void bfs(vector<vector<int>>&grid,vector<vector<int>>& visited,queue<pair<int,int>>q)
    {
        int n=grid.size();
        int m=grid[0].size();
        int level=0;
        while(!q.empty())
        {
           int len=q.size();
           for(int i=0;i<len;i++)
           {
            pair<int,int>temp=q.front();
            int r=temp.first;
            int c=temp.second;
            grid[r][c]=level;
            q.pop();
            for(int i=0;i<coord.size();i++)
            {
              int x=r+coord[i][0];
              int y=c+coord[i][1];
              if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]==2147483647)
              {
                visited[x][y]=1;
                q.push({x,y});
              }
            }
           }
           level++;
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //multibfs starting with 0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                   visited[i][j]=1;
                  q.push({i,j});
                }
                
            }
        }
        bfs(grid,visited,q);
    }
};
