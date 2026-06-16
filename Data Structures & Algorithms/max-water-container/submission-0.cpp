class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi=INT_MIN;
        int n=heights.size();
        int i=0;
        int j=n-1;
        while(i<j)
        {
            int val=(min(heights[i],heights[j])*(j-i));
            maxi=max(maxi,val);
            if(heights[i]<heights[j])
            i++;
            else
            j--;
        }
        return maxi;
    }
};
