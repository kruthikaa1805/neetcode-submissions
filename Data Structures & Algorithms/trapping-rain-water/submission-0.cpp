class Solution {
public:
    int trap(vector<int>& height) {
        /*
        For every index calculate the maximum to its left and the maximum to it's right;
        Therefore we will need 2 arrays mxl and mxr to store them.
        mxl[i]=max(mxl[i-1],arr[i]);//initialli mxl[0]=arr[0];
        mxr[i]=max(arr[i],mxr[i+1]);//traverse from n-1 to 0;and initially mxr[n-1]=arr[n-1];
        At every index the amount of water trapped will be equal to min(mxl,mxr)at that index -height[i];
        The max area of water that can be trapped is sum of all indices.
        Therefore using another array to store trapped water and then sum all elements in this array.
        TC:O(N);SC:O(N);
        Using 2 pointers we can solve in O(N) TC and O(1)SC
       */
       int n=height.size();
      int left=0;
      int right=n-1;
      int left_max=0;
      int right_max=0;
      int water=0;
      while(left<right)
      {
        if(height[left]<=height[right])
        {
            if(height[left]>left_max)
            left_max=height[left];
            else
            water+=left_max-height[left];
            left++;
        }
        else
        {
            if(height[right]>right_max)
            right_max=height[right];
            else
            water+=right_max-height[right];
            right--;
        }
      }
      return water;

    }
};
