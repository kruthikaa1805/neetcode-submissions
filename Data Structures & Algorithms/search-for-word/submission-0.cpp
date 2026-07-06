class Solution {
public:
    vector<vector<int>>coords={{-1,0},{1,0},{0,-1},{0,1}};
    bool dfs(vector<vector<char>>&board,string& word,int idx,vector<vector<int>>&visited,int r,int c)
    {
        int s=word.length();
        int n=board.size();
        int m=board[0].size();
        visited[r][c]=1;
        if(idx==s-1)
        {
            return board[r][c]==word[idx];
        }
        for(int i=0;i<coords.size();i++)
        {
            int x=r+coords[i][0];
            int y=c+coords[i][1];
            if(x>=0 && x<n && y>=0 && y<m && !visited[x][y])
            {
                if(board[x][y]==word[idx+1])
                {
                  if( dfs(board,word,idx+1,visited,x,y)==true)
                  return true;
                }
               
            }
        }
        visited[r][c]=0;
       return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        char ch=word[0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ch==board[i][j])
                {
                if(dfs(board,word,0,visited,i,j)==true)
                return true;
                }
               
            }
        }
        return false;
    }
};
