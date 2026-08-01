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
         
           vector<int>size(n,0);
           vector<int>parent(n);
           for(int i=0;i<n;i++)
           {
            parent[i]=i;
           }
           int comp=n;
           int m=edges.size();
          /* for(vector<int> edge:edges)
           {
            if(unite(edge[0],edge[1],parent,size)==true)
            comp--;
           }
           return comp;*/
           int cnt=0;
           for(vector<int>edge:edges)
           {
            if(unite(edge[0],edge[1],parent,size)==true)
            cnt++;

           }
           return n-cnt;
    }
};
