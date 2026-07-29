class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
           if(board[i][0]=='O')
           {
            q.push({i,0});
            visited[i][0]=1;
            board[i][0]='#';
           }
            if(board[i][m-1]=='O')
           {
            q.push({i,m-1});
            visited[i][m-1]=1;
            board[i][m-1]='#';
           }

        }
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            {
                q.push({0,j});
                visited[0][j]=1;
                board[0][j]='#';
            }
            if(board[n-1][j]=='O')
            {
                q.push({n-1,j});
                visited[n-1][j]=1;
                board[n-1][j]='#';
            }
        }
        vector<vector<int>>coords={{-1,0},{0,-1},{0,1},{1,0}};
        while(!q.empty())
        {
           int len=q.size();
           for(int j=0;j<len;j++)
           {
            pair<int,int>temp=q.front();
            q.pop();
            int r=temp.first;
            int c=temp.second;
            for(int i=0;i<coords.size();i++)
            {
               int x=r+coords[i][0];
               int y=c+coords[i][1];
               if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && board[x][y]=='O')
               {
                   visited[x][y]=1;
                   board[x][y]='#';
                   q.push({x,y});
               } 
            }
           }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='#')
                board[i][j]='O';
                else
                board[i][j]='X';
            }
        }
        return;
    }
};
