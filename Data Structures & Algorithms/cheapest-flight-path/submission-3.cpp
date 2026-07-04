class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
     //use bfs so that only after completing all with 1 stop we go to places with 2 stops
      vector<int>dist(n,1e9);
      unordered_map<int,vector<pair<int,int>>>mp;
      
      for(int i=0;i<flights.size();i++)
      {
        int u=flights[i][0];
        int v=flights[i][1];
        int cost=flights[i][2];
        mp[u].push_back({v,cost});
      }
      queue<pair<int,int>>q;
      q.push({0,src});
      dist[src]=0;
      int cnt=0;
      while(!q.empty())
      {
       int p=q.size();
       for(int i=0;i<p;i++)
       {
           pair<int,int>temp=q.front();
        q.pop();
        int cost=temp.first;
        int curr=temp.second;
        if(cnt>k)
        break;
        for(auto [v,price]:mp[curr])
        {
          if(dist[v]>cost+price)
          {
            dist[v]=cost+price;
            q.push({dist[v],v});
          }
        }
       }
        
        cnt++;
      }
      if(dist[dst]==1e9)
      return -1;
      return dist[dst];
      //cost,curr;
    }
};
