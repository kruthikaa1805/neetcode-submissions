class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        stack<int>st;
        int n=temperatures.size();
        
        for(int i=n-1;i>=0;i--)
        {
             if(st.empty())
             {
                st.push(i);
                ans.push_back(0);
             }
             else
             {
                while(!st.empty() && temperatures[i]>=temperatures[st.top()])
             {
                st.pop();
             }
             if(!st.empty())
             {
                int days=st.top()-i;
                ans.push_back(days);
                st.push(i);
             }
             else
             {
                ans.push_back(0);
                st.push(i);
             }
             }
             

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
