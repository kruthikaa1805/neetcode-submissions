class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        unordered_map<int,vector<int>>graph;
        vector<int>indegree(numCourses,0);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
          int a =prerequisites[i][0];
          int b=prerequisites[i][1];
          graph[b].push_back(a);
          indegree[a]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(int neigh:graph[temp])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                q.push(neigh);
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]>0)
            return {};
        }
        return ans;
    }
};
