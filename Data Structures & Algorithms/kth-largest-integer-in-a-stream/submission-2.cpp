class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
            pq.pop();
        }
        cnt=k;
    }
    int cnt=0;
    priority_queue<int,vector<int>,greater<int>>pq;

    int add(int val) {
        pq.push(val);
        if(pq.size()>cnt)
        pq.pop();
        return pq.top();
    }
};
