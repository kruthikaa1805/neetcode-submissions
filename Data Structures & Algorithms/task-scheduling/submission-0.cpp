class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(char task:tasks)
        {
            mp[task]++;
        }
        priority_queue<int>pq;
        for(auto & it:mp)
        {
           pq.push(it.second);
        }
        queue<pair<int,int>>q;
        int time=0;
        while(!pq.empty() || !q.empty())
        {
           time++;
           if(!pq.empty())
           {
            int freq=pq.top();
            pq.pop();
            freq--;
            if(freq!=0)
            {
                q.push({time+n,freq});
            }
           }
           if(!q.empty())
           {
             auto it=q.front();
             if(it.first==time)
             {
                pq.push(it.second);
                q.pop();
             }
           }
        }
       return time;
    }
};
