class Solution {
public:
    bool isvalid(vector<int>&piles,int h,int max)
    {
        int k=0;
        for(int i=0;i<piles.size();i++)
        {
            int hrs=(piles[i]+max-1)/max;
            k+=hrs;
            if(k>h)
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isvalid(piles,h,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return ans;
    }
};
