class Solution {
public:
    bool isPalindrome(string s)
    {
      
        int n=s.length();
        int i=0;
        int j=n-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(string s,int idx,vector<string>&temp,vector<vector<string>>&ans)
    {
        int n=s.length();
        if(idx==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++)
        {
           if(isPalindrome(s.substr(idx,i-idx+1)))
        {
            temp.push_back(s.substr(idx,i-idx+1));
              helper(s,i+1,temp,ans);
              temp.pop_back();
           
        }
        

        }
        
    }
    vector<vector<string>> partition(string s) {
       int n=s.length();
       vector<string>temp;
       vector<vector<string>>ans;
      
        helper(s,0,temp,ans);
       
       return ans;
    }
};
