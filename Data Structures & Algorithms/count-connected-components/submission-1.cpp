class Solution {
public:
 /* void dfs(unordered_map<int,vector<int>>&graph,vector<int>&visited,int source)
  {
    visited[source]=1;
    for(int neigh:graph[source])
    {
        if(!visited[neigh])
        dfs(graph,visited,neigh);
    }
  }*/
   int findpar(int x,vector<int>&parent)
   {
    if(parent[x]==x)
    return x;
    return parent[x]=findpar(parent[x],parent);
   }
   bool unite(int u,int v,vector<int>&parent,vector<int>&size)
   {
    int pu=findpar(u,parent);
    int pv=findpar(v,parent);
    if(pu==pv)
    return false;
    if(size[pu]<size[pv])
    {
        parent[pu]=pv;
        size[pv]+=size[pu];
    }
    else
    {
       parent[pv]=pu;
        size[pu]+=size[pv]; 
    }
     return true;
   }
    int countComponents(int n, vector<vector<int>>& edges) {
          /* int cnt=0;
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
           return cnt;*/
           vector<int>size(n,0);
           vector<int>parent(n);
           for(int i=0;i<n;i++)
           {
            parent[i]=i;
           }
           int comp=n;
           int m=edges.size();
           for(vector<int> edge:edges)
           {
            if(unite(edge[0],edge[1],parent,size)==true)
            comp--;
           }
           return comp;
    }
};
