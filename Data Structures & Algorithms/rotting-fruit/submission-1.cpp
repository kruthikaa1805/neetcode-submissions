class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int time=0;
        vector<vector<int>>coord={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
           int len=q.size();
           for(int j=0;j<len;j++)
           {
              pair<int,int>temp=q.front();
              int r=temp.first;
              int c=temp.second;
              q.pop();
              for(int i=0;i<coord.size();i++)
              {
                int x=r+coord[i][0];
                int y=c+coord[i][1];
                if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]==1)
                {
                     visited[x][y]=1;
                     q.push({x,y});
                     grid[x][y]=2;
                }
              }
           }
           if(!q.empty())
           time++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
        return time;
    }
};
