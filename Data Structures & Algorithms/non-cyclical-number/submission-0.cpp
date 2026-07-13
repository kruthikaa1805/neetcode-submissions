class Solution {
public:
    int squared(int n)
    {
        int m=n;
        int ans=0;
        while(m>0)
        {
          int digit=m%10;
          ans+=digit*digit;
          m=m/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_map<int,int>mp;
        int square=0;
        int m=n;
        while(square!=1)
        {
            square=squared(m);
            if(square==1)
            return true;
            else
            {
                if(mp.find(square)!=mp.end())
                return false;
                else
                mp[square]=1;
            }
            m=square;
        }
    }
};
