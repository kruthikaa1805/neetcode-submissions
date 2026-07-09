class Solution {
public:
   int calculate(int i,int j,string &s)
   {
    int n=s.length();
    int cnt=0;
    while(i>=0 && j<n)
    {
        if(s[i]==s[j])
        {
            cnt++;
            i--;
            j++;
        }
        else
        break;
    }
    return cnt;
   }
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=calculate(i,i,s);
            ans+=calculate(i,i+1,s);
        }
        return ans;
    }
};
