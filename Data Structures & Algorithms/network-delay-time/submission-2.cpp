class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e9);
        vector<vector<pair<int,int>>>graph(n+1);
        for(int i=0;i<times.size();i++)
        {
            int a=times[i][0];
            int b=times[i][1];
            int tim=times[i][2];
            graph[a].push_back({b,tim});
        }
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            const pair<int,int>temp=pq.top();
            int dis=temp.first;
            int node=temp.second;
            pq.pop();
            for(auto it:graph[node])
            {

                if((dis+it.second<dist[it.first]))
                {
                    dist[it.first]=dis+it.second;
                    pq.push({dist[it.first],it.first});
                }

            }
        }
        int maxi=0;
        for(int i=1;i<n+1;i++)
        {
            if(dist[i]==1e9)
            return -1;
            maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};
