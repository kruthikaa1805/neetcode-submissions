class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>graph;
        int n=prerequisites.size();
         vector<int>indegree(numCourses,0);
        for(int i=0;i<n;i++)
        {
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            graph[b].push_back(a);//1->0
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
            return false;
        }
        return true;
    }
};
