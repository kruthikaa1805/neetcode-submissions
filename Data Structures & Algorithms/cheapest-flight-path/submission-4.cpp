class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int stops=0;
        unordered_map<int,vector<pair<int,int>>>mp;
        int m=flights.size();
        for(int i=0;i<m;i++)
        {
          int u=flights[i][0];
          int v=flights[i][1];
          int cost=flights[i][2];
          mp[u].push_back({v,cost});
        }
        vector<int>dist(n,1e9);
         queue<pair<int,int>>q;
         q.push({0,src});
         dist[src]=0;
         while(!q.empty())
         {
           int len=q.size();
           if(stops>k)
           break;
           stops++;
           for(int i=0;i<len;i++)
           {
            pair<int,int>temp=q.front();
            q.pop();
            int cost=temp.first;
            int node=temp.second;
            for(auto it:mp[node])
            {
               int adjnode=it.first;
               int edgewt=it.second;
               if(edgewt+cost<dist[adjnode])
               {
                dist[adjnode]=edgewt+cost;
                q.push({dist[adjnode],adjnode});
               }
            }
           }
         }
         if(dist[dst]==1e9)
         return -1;
         return dist[dst];
    }
};
