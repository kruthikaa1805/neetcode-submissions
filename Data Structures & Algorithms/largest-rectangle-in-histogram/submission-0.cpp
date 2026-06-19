class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nsr;
        vector<int>nsl;
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                nsl.push_back(-1);
                st.push({i,heights[i]});
            }
            else
            {
               while(!st.empty() && heights[i]<=st.top().second)
               st.pop();
               if(st.empty())
               {
                nsl.push_back(-1);
                st.push({i,heights[i]});
               }
               else if(heights[i]>st.top().second)
               {
                nsl.push_back(st.top().first);
                st.push({i,heights[i]});
               }
                
               
            }
            
        }
        stack<pair<int,int>>st2;
        for(int i=n-1;i>=0;i--)
        {
            if(st2.empty())
            {
                nsr.push_back(n);
                st2.push({i,heights[i]});
            }
              else
            {
               while(!st2.empty() && heights[i]<=st2.top().second)
               st2.pop();
               if(st2.empty())
               {
                nsr.push_back(n);
                st2.push({i,heights[i]});
               }
               else if(heights[i]>st2.top().second)
               {
                nsr.push_back(st2.top().first);
                st2.push({i,heights[i]});
               }
                
               
            }
        }
        reverse(nsr.begin(),nsr.end());
        int maxi=0;
        for(int i=0;i<n;i++)
        {
          int width=(nsr[i]-nsl[i]-1);
          int area=heights[i]*width;
          maxi=max(maxi,area);
        }
        return maxi;
    }
};
