class Solution {
public:
    vector<vector<int>>coords={{-1,0},{0,-1},{1,0},{0,1}};
    void helper(vector<vector<int>>&grid,queue<pair<int,int>>&q)
    {
      int n=grid.size();
      int m=grid[0].size();
      int level=0;
      while(!q.empty())
      {
        int siz=q.size();
        level++;
        for(int i=0;i<siz;i++)
        {
        pair<int,int>temp=q.front();
        q.pop();
        int r=temp.first;
        int c=temp.second;
        
        for(int i=0;i<coords.size();i++)
        {
            int x=r+coords[i][0];
            int y=c+coords[i][1];
            if(x>=0 && x<n && y>=0 &&y<m )
            {
              if(grid[x][y]!=-1 && level<grid[x][y])
              {
                grid[x][y]=level;
                q.push({x,y});
              }
              
            }
        }
        }
      
      }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int inf=2147483647;
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
            if(grid[i][j]==0)
            {
              q.push({i,j});
            }
          }
        }
        helper(grid,q);
return;
    }
};
