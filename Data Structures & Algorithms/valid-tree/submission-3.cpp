class Solution {
public:
    bool iscycle(int n,int i,unordered_map<int,vector<int>>&mp,vector<int>&visited)
    {
        queue<pair<int,int>>q;
        q.push({i,-1});
        visited[i]=1;
        while(!q.empty())
        {
          pair<int,int>temp=q.front();
          int node=temp.first;
          int parent=temp.second;
          q.pop();
         
          for(int adjnode:mp[node])
          {
            if(!visited[adjnode])
            {
              q.push({adjnode,node});
              visited[adjnode]=1;
            }
            else if(adjnode!=parent)
            return true;
          }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
          //if cycle return false
          int m=edges.size();
          unordered_map<int,vector<int>>mp;
          for(int i=0;i<m;i++)
          {
            int a=edges[i][0];
            int b=edges[i][1];
            mp[a].push_back(b);
            mp[b].push_back(a);
          }
          vector<int>visited(n,0);
          if(iscycle(n,0,mp,visited)==true)
            return false;
          for(int i=0;i<n;i++)
          {
            if(!visited[i])
            {
              return false;
            }
          }
          return true;

    }
};
