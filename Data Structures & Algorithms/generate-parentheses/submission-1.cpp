class Solution {
public:
    void helper(int open,int close,string &temp,vector<string>&ans)
    {
        if(open==0 && close==0)
        {
         ans.push_back(temp);
        return;
        }
       
         if(open>0)
        {
            temp.push_back('(');
            helper(open-1,close,temp,ans);
            temp.pop_back();
        }
        if(close>open)
        {
             temp.push_back(')');
            helper(open,close-1,temp,ans);
            temp.pop_back();
        }
      
       return; 
    }

    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string>ans;
        helper(n,n,temp,ans);
        return ans;
    }
};
