class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<int,vector<int>>mp;
        unordered_map<string,int>mp2;
        unordered_map<string,int>dead;
        for(int i=0;i<deadends.size();i++)
        {
            dead[deadends[i]]++;
        }
        for(int i=0;i<9;i++)
        {
            mp[i].push_back(i+1);
            mp[i+1].push_back(i);
        }
        mp[0].push_back(9);
        mp[9].push_back(0);
        string initial="0000";
        if(dead.find(initial)!=dead.end())
        return -1;
        queue<string>q;
        q.push(initial);
        mp2[initial]++;
        int level=-1;
        while(!q.empty())
        {
            int len=q.size();
            level++;
            for(int i=0;i<len;i++)
            {
                string temp=q.front();
                q.pop();
                if(temp==target)
                return level;
               
                for(int j=0;j<4;j++)
                {
                     char ch=temp[j];
                     int a=ch-'0';
                     for(auto it:mp[a])
                     {
                        temp[j]=it+'0';
                        if(mp2.find(temp)==mp2.end() && dead.find(temp)==dead.end())
                        {
                             q.push(temp);
                             mp2[temp]++;
                        }
                        
                     }
                     temp[j]=ch;
                }
            }
        }
        return -1;
    }
};