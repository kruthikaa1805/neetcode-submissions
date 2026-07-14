class Solution {
public:
    int findones(int n)
    {
        int cnt=0;
        int num=n;
        while(num>0)
        {
            if(num%2==1)
            cnt++;
            num=num/2;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>ans (n+1);
        for(int i=0;i<=n;i++)
        {
            ans[i]=findones(i);
        }
        return ans;
    }
};
