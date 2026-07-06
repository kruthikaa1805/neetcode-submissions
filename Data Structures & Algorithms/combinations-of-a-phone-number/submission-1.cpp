class Solution {
public:
    void helper(vector<vector<char>>&keypad,int idx,string&digits,string &path,vector<string>&ans)
    {
        int n=digits.size();
          if(idx==n)
          {
            if(path.size()==digits.size())
            ans.push_back(path);
            return;
          }
          int num=digits[idx]-'0';
          for(int i=0;i<keypad[num-2].size();i++)
          {
            path.push_back(keypad[num-2][i]);
            helper(keypad,idx+1,digits,path,ans);
            path.pop_back();
          }
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>>keypad={{'a','b','c'},
        {'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},
        {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        if(digits.size()==0)
        return {};
        string path="";
        vector<string>ans;
        helper(keypad,0,digits,path,ans);
        if(ans.size()==0)
        return {};
        return ans;
    }
};
