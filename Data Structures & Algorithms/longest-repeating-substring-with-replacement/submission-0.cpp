class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0;
        int j=0;
        int len=0;
        int flips=0;
        int max_freq=0;
        unordered_map<char,int>mp;
        while(j<n)
        {
            mp[s[j]]++;
            max_freq=max(max_freq,mp[s[j]]);
            flips=j-i+1-max_freq;
            if(flips<=k)
            {
                len=max(len,j-i+1);
                j++;
            }
            else
            {
                mp[s[i]]--;
                i++;
                j++;
            }
        }
        return len;
    }
};
