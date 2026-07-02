class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O' )
            {
                q.push({0,j});
                visited[0][j]=1;
                board[0][j]='#';
            }
            if( board[n-1][j]=='O')
            {
                q.push({n-1,j});
                visited[0][j]=1;
                board[n-1][j]='#';
            }
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' )
            {
                q.push({i,0});
                visited[i][0]=1;
                board[i][0]='#';
            }
            if( board[i][m-1]=='O')
            {
                q.push({i,m-1});
                visited[i][m-1]=1;
                board[i][m-1]='#';
            }
        }
        vector<vector<int>>coord={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            pair<int,int>temp=q.front();
            int r=temp.first;
            int c=temp.second;
            q.pop();
            for(int i=0;i<coord.size();i++)
            {
                int x=r+coord[i][0];
                int y=c+coord[i][1];
                if(x>=0 && x<n &&y>=0 && y<m && !visited[x][y])
                {
                    if(board[x][y]=='O')
                    {
                        q.push({x,y});
                        visited[x][y]=1;
                        board[x][y]='#';
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
    }
};
