class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<int,string>>>mp;
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())
        return "";

        const auto & val=mp[key];
        int left=0;
        int right=val.size()-1;
        int ans=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(val[mid].first<=timestamp)
            {
               ans=mid;
               left=mid+1;
            }
            
            else
               right=mid-1;
        }
        if(ans==-1)
        return "";
        return val[ans].second;
    }
};
