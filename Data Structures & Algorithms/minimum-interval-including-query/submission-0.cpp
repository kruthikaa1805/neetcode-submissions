class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        int n=queries.size();
        int m=intervals.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            int mini=INT_MAX;
           for(int j=0;j<m;j++)
           {
            if(intervals[j][0]<=queries[i] && intervals[j][1]>=queries[i])
            {
                int len=intervals[j][1]-intervals[j][0]+1;
                mini=min (mini,len);
            }
           }
           if(mini==INT_MAX)
           ans[i]=-1;
           else
           ans[i]=mini;
        }
       return ans;
    }
};
