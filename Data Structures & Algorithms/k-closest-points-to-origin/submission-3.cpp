class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        int n=points.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            int dist=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            pq.push({dist,i});
            if(pq.size()>k)
            pq.pop();

        }
        while(!pq.empty())
        {
          pair<int,int>temp=pq.top();
          pq.pop();
          int idx=temp.second;
          ans.push_back({points[idx][0],points[idx][1]});
        }
        return ans;
    }
};
