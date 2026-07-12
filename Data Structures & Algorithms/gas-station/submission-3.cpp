class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=0;
        int total_cost=0;
        for(int i=0;i<n;i++)
        {
            
            int cnt=0;
            int idx=i;
            int available=0;
            
            while(cnt<n)
            {
               
                available+=gas[idx];
                available=available-cost[idx];
                if(available<0)
                break;
                cnt++;
                idx=(idx+1)%n;

            }
            if(cnt==n)
            return i;
        }
        return -1;
        
    }
};
