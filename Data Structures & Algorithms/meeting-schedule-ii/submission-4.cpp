/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const Interval&a ,Interval&b)
        {
            return a.start<b.start;
        });
        priority_queue<int,vector<int>,greater<int>>pq;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            while(!pq.empty() && pq.top()<=intervals[i].start)
            {
                pq.pop();
                
            }
            pq.push(intervals[i].end);
            /*if(pq.empty() || pq.top()>intervals[i].start)
            {
                pq.push(intervals[i].end);
            }*/
            int m=pq.size();
           maxi=max(maxi,m);
        }
        return maxi;
    }
};
