class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //length of window should be equal to size of map.
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int len=0;
        while(j<s.length())
        {
            mp[s[j]]++;
            if(j-i+1==mp.size())
            {
                len=max(len,j-i+1);
                j++;
            }
            else if(j-i+1>mp.size())
            {
                while(j-i+1>mp.size())
                {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                mp.erase(s[i]);
                i++;
                }
               j++;
            }
        }
        return len;
    }
};
