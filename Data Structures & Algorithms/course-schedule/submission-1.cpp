class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>mp;
        vector<int>indegree(numCourses,0);
        //b.push_back(a);
        int n=prerequisites.size();
        for(int i=0;i<n;i++)
        {
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            mp[b].push_back(a);
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
            int node=q.front();
            q.pop();
            for(int adjnode:mp[node])
            {
                indegree[adjnode]--;
                if(indegree[adjnode]==0)
                q.push(adjnode);
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]!=0)
            return false;
        }
        return true;

    }
};
