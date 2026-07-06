class Solution {
public:
   bool isSafe(vector<string>&board,int row,int col,int n)
   {
    int r=row;
    int c=col;
    //horizontal
    while(c>=0)
    {
        if(board[r][c]=='Q')
        return false;
        c--;
    }
    //upward left
    r=row;
    c=col;
    while(r>=0 && c>=0)
    {
        if(board[r][c]=='Q')
        return false;
        r--;
        c--;
    }
    //downward left
    r=row;
    c=col;
    while(r<n && c>=0)
    {
        if(board[r][c]=='Q')
        return false;
        r++;
        c--;
    }
    return true;
   }
   void helper(int col,int n,vector<string>&board,vector<vector<string>>&ans)
   {
    if(col==n)
    {
        ans.push_back(board);
        return;
    }
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,i,col,n)==true)
            {
                 board[i][col]='Q';
                 helper(col+1,n,board,ans);
                 board[i][col]='.';
            }
            

        }
   }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        helper(0,n,board,ans);
        return ans;
    }
};
