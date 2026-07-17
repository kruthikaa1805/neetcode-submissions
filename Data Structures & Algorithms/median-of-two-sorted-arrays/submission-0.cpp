class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int total=n+m;
        int a,b;
        if((total)%2==0)
        {
            a=((n+m)/2)-1;
            b=(n+m)/2;
        }
        else
        {
            a=(n+m)/2;
            b=a;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums1[i]);
        }
        for(int j=0;j<m;j++)
        {
            pq.push(nums2[j]);
        }
        int cnt=0;
        double ans=0;
       
        while(cnt<=a)
        {
            int val=pq.top();
            pq.pop();
           
            if(cnt==a)
            ans+=val;
             cnt++;

        }
        if(b!=a)
        {
            ans+=pq.top();
            ans=ans/2.0;
        }
        return ans;
    }
};
