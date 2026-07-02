class Solution {
public:
    int findpar(int x,vector<int>&parent)
    {
        if(parent[x]==x)
        return x;
        return parent[x]=findpar(parent[x],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1);
        vector<int>size(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    
        for(vector<int> &edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int pu=findpar(u,parent);
            int pv=findpar(v,parent);
            if(pu==pv)
            return {u,v};
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
        }
        return {};
    }
};
