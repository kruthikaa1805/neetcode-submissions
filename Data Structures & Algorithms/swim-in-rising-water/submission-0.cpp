class Solution {
public:
    vector<vector<int>>coords={{-1,0},{1,0},{0,1},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        //time,x,y
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({grid[0][0],0,0});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int maxi=INT_MIN;
        while(!pq.empty())
        {
          auto [time,r,c]=pq.top();
          pq.pop();
          if(visited[r][c])
          continue;
          visited[r][c]=1;
          maxi=max(maxi,time);
          if(r==n-1 && c==m-1)
          return maxi;
          for(int i=0;i<coords.size();i++)
          {
            int x=r+coords[i][0];
            int y=c+coords[i][1];
            if(x>=0 && y>=0 && x<n && y<m)
            {
                pq.push({grid[x][y],x,y});
            }
          }
        }
        return -1;
    }
};
