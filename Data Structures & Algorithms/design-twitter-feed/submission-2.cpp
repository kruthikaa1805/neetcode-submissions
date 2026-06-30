class Twitter {
public:
    Twitter() {
         time=0;
    }
    int time;
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>following;
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
      vector<int>ans;
       for(auto & it:tweets[userId])
       {
           int t=it.first;
           int twe=it.second;
           pq.push({t,twe});
       }
       for(auto & it:following[userId])
       {
        for(auto & temp:tweets[it])
        
        pq.push(temp);
       }
      
        while(!pq.empty())
        {
         ans.push_back(pq.top().second);
        pq.pop();
        if(ans.size()==10)
        return ans;
        }
       
       return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followeeId!=followerId)
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
