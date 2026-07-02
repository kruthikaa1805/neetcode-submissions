class Solution {
public:
  void dfs(unordered_map<int,vector<int>>&graph,vector<int>&visited,int source)
  {
    visited[source]=1;
    for(int neigh:graph[source])
    {
        if(!visited[neigh])
        dfs(graph,visited,neigh);
    }
  }
    int countComponents(int n, vector<vector<int>>& edges) {
           int cnt=0;
           int m=edges.size();
           unordered_map<int,vector<int>>graph;
           for(int i=0;i<m;i++)
           {
            int a=edges[i][0];
            int b=edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
           }
           vector<int>visited(n,0);
           for(int i=0;i<n;i++)
           {
            if(!visited[i])
            {
                cnt++;
                dfs(graph,visited,i);
            }
           }
           return cnt;
    }
};
