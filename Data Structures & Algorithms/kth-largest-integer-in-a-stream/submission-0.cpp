class KthLargest {
public:
int limit;
priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        limit=k;
        for(int i:nums)
        {
            pq.push(i);
            if(pq.size()>k)
            pq.pop();
        }

    }
    
    int add(int val) {
        
        pq.push(val);
        if(pq.size()>limit)
        pq.pop();
        return pq.top();
    }
};
