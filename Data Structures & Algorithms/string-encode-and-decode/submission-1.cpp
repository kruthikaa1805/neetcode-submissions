class Solution {
public:

    string encode(vector<string>& strs) {
         string ans="";
         for(int i=0;i<strs.size();i++)
         {
            ans+=to_string(strs[i].length())+'#'+strs[i];
         }
         return ans;
    }

    vector<string> decode(string s) {
        int n=s.length();
        string temp="";
        vector<string>ans;
        int i=0;
        while(i<n)
        {
            string temp="";
            while(s[i]!='#')
            {
               temp+=s[i];
               i++;
            }
            int len=stoi(temp);
            string res;
            for(int j=i+1;j<i+1+len;j++)
            {
              res+=s[j];
            }
            ans.push_back(res);
            i=i+1+len;
        }
        return ans;
    }
};
