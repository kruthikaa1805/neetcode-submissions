class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       /* deque<pair<int,int>>dq;
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
        return ans;*/
        
    deque<int>dq;
    vector<int>ans;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        while(!dq.empty() && nums[i]>nums[dq.back()])
        dq.pop_back();
        dq.push_back(i);

        if(!dq.empty() && dq.front()<=i-k)
        {
            dq.pop_front();
        }
        //for first attempt this if should be written after that it will work always
        // because the condition will always be true
        if(i>=k-1)
        ans.push_back(nums[dq.front()]);

    }
    return ans;
    }
};
