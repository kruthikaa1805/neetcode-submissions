class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<double,double>> temp;
        for(int i=0;i<n;i++)
        {
           temp.push_back({position[i],speed[i]});
        }
        sort(temp.begin(),temp.end());
        stack<double>st;
        for(int i=n-1;i>=0;i--)
        {
           double time=(target-temp[i].first)/temp[i].second;
           if(st.empty())
           st.push(time);
           else
           {
            if(time<=st.top())
            continue;
            else
            st.push(time);
           }

        }
        return st.size();
    }
};
