class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt=0;
        int time=0;
        vector<int>elem(26,0);
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        int m=tasks.size();
        for(int i=0;i<m;i++)
        {
           int val=tasks[i]-'A';
           elem[val]++;
        }
        for(int i=0;i<26;i++)
        {
            if(elem[i]>0)
            pq.push(elem[i]);
        }
        while(!pq.empty() || !q.empty())
        {
            
            if(!pq.empty())
            {
               int val=pq.top();
            pq.pop();
            val--;
           
            if(val>0)
            q.push({time,val});
            }
            time++;
            if(!q.empty() && ((time-q.front().first)>n))
            {
                pair<int,int>temp=q.front();
                q.pop();
                pq.push(temp.second);
            }

        }
        return time;
    }
};
