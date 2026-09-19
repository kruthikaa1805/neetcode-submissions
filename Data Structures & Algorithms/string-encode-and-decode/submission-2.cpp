class Solution {
public:

    string encode(vector<string>& strs) {
          string str;
          for(int i=0;i<strs.size();i++)
          {
            
            str+=to_string(strs[i].length())+'#'+strs[i];
          }
          return str;
    }

    vector<string> decode(string s) {
           vector<string>ans;
           int i=0;
           while(i<s.length())
           {
               int dig=0;
               while(s[i]!='#')
               {
                dig=dig*10+(s[i]-'0');
                i++;
               }
               string temp=s.substr(i+1,dig);
               ans.push_back(temp);
               i=i+dig+1;
           }
           return ans;
    }
};
