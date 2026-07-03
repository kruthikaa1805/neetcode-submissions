class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<m;i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int t=times[i][2];
            adj[u].push_back({v,t});
        }
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty())
        {
            auto [dis,curr]=pq.top();
            pq.pop();
            if (dis > dist[curr]) continue;
            for(auto [v,t]:adj[curr])
            {
                if(dist[v]>dist[curr]+t)
                {
                    dist[v]=dist[curr]+t;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
        {
             ans=max(ans,dist[i]);

        }
        if(ans==1e9)
        return -1;
        return ans;
    }
};
