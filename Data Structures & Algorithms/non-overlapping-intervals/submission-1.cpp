class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int cnt=0;
        sort(intervals.begin(),intervals.end());
        int prev=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(prev>intervals[i][0])
            {
                cnt++;
                if(prev>intervals[i][1])
                prev=intervals[i][1];
            }
            else
            {
               prev= intervals[i][1];
            }
        }
        return cnt;
    }
};
