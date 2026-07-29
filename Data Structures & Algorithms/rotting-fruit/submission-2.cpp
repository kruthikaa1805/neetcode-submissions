class Solution {
public:
    vector<vector<int>>coords={{-1,0},{0,-1},{1,0},{0,1}};
    int helper(vector<vector<int>>&grid, queue<pair<int,int>>q)
    {
        int n=grid.size();
        int m=grid[0].size();
        int time=0;
       while(!q.empty())
       {
           int siz=q.size();
         
           for(int i=0;i<siz;i++)
           {
            pair<int,int>temp=q.front();
            int r=temp.first;
            int c=temp.second;
            q.pop();
            for(int i=0;i<coords.size();i++)
            {
                int x=r+coords[i][0];
                int y=c+coords[i][1];
                if(x>=0 && x<n && y>=0 && y<m  && grid[x][y]==1)
                {
                    grid[x][y]=2;
                   q.push({x,y});
                }
            }
           }
           if(!q.empty())
             time++;

       }
       return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                 q.push({i,j});
                }
               
            }
        }
       int ans=helper(grid,q);
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            return -1;
        }
       }
       return ans;
    }
};
