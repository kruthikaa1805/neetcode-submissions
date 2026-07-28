class Solution {
public:
    void helper(string &digits,vector<string>&ans,vector<vector<char>>&keypad,string &temp,int idx)
    {
         if(idx==digits.length())
         {
           ans.push_back(temp);
           return;
         }
         int dig=digits[idx]-'0';
         int i=dig-2;
         for(int j=0;j<keypad[i].size();j++)
         {
            temp.push_back(keypad[i][j]);
            helper(digits,ans,keypad,temp,idx+1);
            temp.pop_back();
         }
          return;
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>>keypad={{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        int n=digits.length();
        if(n==0)
        return {};
         string temp="";
         vector<string>ans;
         helper(digits,ans,keypad,temp,0);
         return ans;
    }
};
