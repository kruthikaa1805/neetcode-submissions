class Solution {
public:
    bool checkbfs(int source,unordered_map<int,vector<int>>&graph,vector<int>&visited)
    {
         queue<pair<int,int>>q;
         q.push({source,-1});
         visited[source]=1;
         while(!q.empty())
         {
            pair<int,int>temp=q.front();
            q.pop();
            int val=temp.first;
            int parent=temp.second;
            for(int neigh:graph[val])
            {
                if(!visited[neigh])
                {
                    q.push({neigh,val});
                    visited[neigh]=1;
                }
                else if(neigh!=parent)
                return false;
            }
         }
         return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
          //there should be no cycle
          int m=edges.size();
          unordered_map<int,vector<int>>graph;
          for(int i=0;i<m;i++)
          {
            int a= edges[i][0];
            int b= edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
          }
       
        vector<int>visited(n,0);
       
                if(checkbfs(0,graph,visited)==false)
                return false;
         for(int i=0;i<n;i++)
         {
            if(!visited[i])
            return false;
         }
         return true;
    }
   
};
