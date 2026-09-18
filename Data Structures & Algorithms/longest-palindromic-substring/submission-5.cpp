class Solution {
public:
    int solve(string s,int i,int j)
    {
        int len=0;
        int n=s.length();
        while(i>=0 && j<n)
        {
            if(s[i]==s[j])
            {
                len=j-i+1;
                i--;
                j++;
            }
            else
            break;
        }
        return len;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int len=0;
        int cen=-1;
         for(int i=0;i<n;i++)
         {
            int odd=solve(s,i,i);
            int even=solve(s,i,i+1);
            int maxi=max(odd,even);
            if(maxi>len)
            {
                len=maxi;
                cen=i;
            }
         }
         int start=cen-(len-1)/2;
         string ans=s.substr(start,len);
         return ans;
    }
};
