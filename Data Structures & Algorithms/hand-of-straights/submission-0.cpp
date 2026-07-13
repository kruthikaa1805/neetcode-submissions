class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)
        return false;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[hand[i]]++;
        }
        while(!mp.empty())
        {
            int val=mp.begin()->first;
            mp[val]--;
            if(mp[val]==0)
            mp.erase(val);
            for(int i=1;i<groupSize;i++)
            {
                if(mp.find(val+1)==mp.end())
                return false;
                val=val+1;
                mp[val]--;
                if(mp[val]==0)
                mp.erase(val);

            }
        }
        return true;
    }
};
