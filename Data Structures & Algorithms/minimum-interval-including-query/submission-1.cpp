class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
       /* int n=queries.size();
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
       return ans;*/
       sort(intervals.begin(),intervals.end());

       int n=queries.size();
       vector<pair<int,int>>q;
       for(int i=0;i<n;i++)
       {
        q.push_back({queries[i],i});
       }
       sort(q.begin(),q.end());
       vector<int>ans(n);
       int m=intervals.size();
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       int j=0;
       for(int i=0;i<n;i++)
       {
        int val=q[i].first;
        int idx=q[i].second;
        
        while(j<m && intervals[j][0]<=val)
        {
            int dist=intervals[j][1]-intervals[j][0]+1;
            pq.push({dist,intervals[j][1]});
            j++;
        }
        while(!pq.empty() && pq.top().second<val)
        {
            pq.pop();
        }
        if(pq.empty())
        ans[idx]=-1;
        else
        ans[idx]=pq.top().first;
       }
       return ans;
    }
};
