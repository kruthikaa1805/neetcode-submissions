class Solution {
public:
    vector<vector<int>>coords={{-1,0},{0,-1},{1,0},{0,1}};
    bool dfs(int r,int c,string &word,int idx,vector<vector<char>>&board,vector<vector<int>>&visited)
    {
        if(board[r][c]!=word[idx])
        return false;
        visited[r][c]=1;
        int n=board.size();
        int m=board[0].size();
        if(idx==word.length()-1)
        return true;
        for(int i=0;i<coords.size();i++)
        {
            int x=r+coords[i][0];
            int y=c+coords[i][1];
            if(x>=0 && x<n && y>=0 && y<m && !visited[x][y])
            {
                if(dfs(x,y,word,idx+1,board,visited)==true)
                return true;
            }
            
        }
        visited[r][c]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(i,j,word,0,board,visited)==true)
                    return true;
                }
            }
        }
        return false;
    }
};
