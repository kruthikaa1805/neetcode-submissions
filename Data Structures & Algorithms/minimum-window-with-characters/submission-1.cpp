class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<t.length();i++)
        mp[t[i]]++;
        int i=0;
        int cnt=0;
        int n=t.length();
        int j=0;
        int len=INT_MAX;int idx=0;
        while(j<s.length())
        {
            if(mp[s[j]]>0)
            {
                cnt++;
            }
            mp[s[j]]--;
            if(cnt<n)
            j++;
            else if (cnt==n)
            {
                while(cnt==n)
                {
                if(j-i+1<len)
                {
                    len=j-i+1;
                   idx=i;
                }
                
                mp[s[i]]++;
                if(mp[s[i]]>0)
                cnt--;
                i++;
                }
               j++; 
            }   
        }
        if(len==INT_MAX)
        return "";
       return s.substr(idx,len);
    }
};
