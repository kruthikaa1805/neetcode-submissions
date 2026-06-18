class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        for(int i=0;i<s1.length();i++)
        mp[s1[i]]++;
        int j=0;
        int i=0;
        int n=s1.length();
        while(j<s2.length())
        {
           mp[s2[j]]--;
           if(mp[s2[j]]==0)
           mp.erase(s2[j]);
           if(j-i+1<n)
           j++;
           else if(j-i+1==n && mp.size()==0)
            return true;
            else
            {
                mp[s2[i]]++;
                if(mp[s2[i]]==0)
                mp.erase(s2[i]);
                i++;
                j++;
            }
           }
           return false;
        }
        
    };

