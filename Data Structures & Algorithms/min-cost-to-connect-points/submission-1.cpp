class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //mst
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,0});
       int n=points.size();
       vector<int>visited(n,0);
       int min_cost=0;
       while(!pq.empty())
       {
        auto [cost,idx]=pq.top();
        pq.pop();
        if(visited[idx]==1)
        continue;
        visited[idx]=1;
        min_cost+=cost;
        for(int i=0;i<n;i++)
        {
            if(visited[i])
            continue;
            int x=abs(points[i][0]-points[idx][0]);
            int y=abs(points[i][1]-points[idx][1]);
            int dist=x+y;
            pq.push({dist,i});
        }
       }
       return min_cost;
    }
};
