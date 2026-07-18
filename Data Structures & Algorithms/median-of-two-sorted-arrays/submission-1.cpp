class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        int n=nums1.size();
        int m=nums2.size();
        int half=(n+m+1)/2;
        int start=0;
        int end=n;
        while(start<=end)
        {
            int mid1=start+(end-start)/2;
            int mid2=half-mid1;
            int l1=INT_MIN;
            if(mid1>=1)l1=nums1[mid1-1];
            int l2=INT_MIN;
            if(mid2>=1)l2=nums2[mid2-1];
            int r2=INT_MAX;
            int r1=INT_MAX;
            if(mid1<n)
            r1=nums1[mid1];
            if(mid2<m)
            r2=nums2[mid2];

            if(l1<=r2 && l2<=r1)
            {
                if((n+m)%2==0)
                {
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else
                return max(l1,l2);
            }
            else if(l1>r2)
            end=mid1-1;
            else
            start=mid1+1;
            
        }
        return 0;
    }
};
