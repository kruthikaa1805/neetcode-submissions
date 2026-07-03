class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;
        //row,column,pacific=0/atlantic=1;
        for(int j=0;j<m;j++)
        {
            q.push({0,j,0});
            pacific[0][j]=1;
            q.push({n-1,j,1});
            atlantic[n-1][j]=1;
        }
       for(int i=0;i<n;i++)
       {
        q.push({i,0,0});
        pacific[i][0]=1;
        q.push({i,m-1,1});
        atlantic[i][m-1]=1;
       }
       vector<vector<int>>coords={{1,0},{-1,0},{0,1},{0,-1}};
       while(!q.empty())
       {
        auto[row,col,ocean]=q.front();
        q.pop();
        for(int i=0;i<coords.size();i++)
        {
            int x=row+coords[i][0];
            int y=col+coords[i][1];
            if(x>=0 && x<n && y>=0 && y<m && heights[x][y]>=heights[row][col])
            {
                if(ocean==0 && !pacific[x][y])
                {
                   pacific[x][y]=1;
                   q.push({x,y,0});
                }
                
                else if(ocean==1 && !atlantic[x][y])
                {
                     atlantic[x][y]=1;
                     q.push({x,y,1});
                }
               
            }
        }
        
       }
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
