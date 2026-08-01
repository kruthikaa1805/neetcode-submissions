class Solution {
public:
     int findpar(int x,vector<int>&parent)
     {
        if(parent[x]==x)
        return x;
        return parent[x]=findpar(parent[x],parent);
     }
     void unionbysize(int u,int v,vector<int>&parent,vector<int>&size)
     {
        int pu=findpar(u,parent);
        int pv=findpar(v,parent);
       
        if(size[pu]<size[pv])
        {
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
        else
        {
             size[pu]+=size[pv];
             parent[pv]=pu;
        }
        return ;
     }
    int countComponents(int n, vector<vector<int>>& edges) {
             vector<int>parent(n);
             vector<int>size(n,0);
             for(int i=0;i<n;i++)
             {
                parent[i]=i;
             }
           int m=edges.size();
           for(int i=0;i<m;i++)
           {
            int u=edges[i][0];
            int v=edges[i][1];
            unionbysize(u,v,parent,size);
           }
           unordered_map<int,int>mp;
          for(int i=0;i<n;i++)
          {
            mp[findpar(i,parent)]++;

          }
     return mp.size();
    }
};
