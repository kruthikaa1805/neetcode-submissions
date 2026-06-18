class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        int n=nums.size()-k+1;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            while(!dq.empty() && nums[i]>dq.back().first)
            dq.pop_back();
            dq.push_back({nums[i],i});
            if(!dq.empty() && dq.front().second<=i-k)
            dq.pop_front();
            if(i>=k-1)
            ans.push_back(dq.front().first);

        }
        return ans;
        
    }
};
