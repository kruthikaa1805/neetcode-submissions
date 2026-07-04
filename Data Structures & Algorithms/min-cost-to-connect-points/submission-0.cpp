class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //MST-prims algo
       int n=points.size();
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       vector<int>visited(n,0);
       pq.push({0,0});
       int min_cost=0;
       while(!pq.empty())
       {
        auto [dist,curr]=pq.top();
        pq.pop();
        if(visited[curr])
        continue;
        visited[curr]=1;
        min_cost+=dist;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                int x=abs(points[i][0]-points[curr][0]);
                int y=abs(points[i][1]-points[curr][1]);
                int cost=x+y;
                pq.push({cost,i});
            }
        }
       }
       return min_cost;
    }
};
