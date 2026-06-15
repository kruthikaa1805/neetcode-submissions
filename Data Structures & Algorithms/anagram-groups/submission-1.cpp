class Solution {
public:
    string getone(string& s)
    {
       string ans=s;
       sort(ans.begin(),ans.end());
       return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        int n=strs.size();
        /*for(int i=0;i<n;i++)
        {
            string temp=getone(strs[i]);
            mp[temp].push_back(i);
        }
        for(auto it:mp)
        {
            vector<int>temp=it.second;
            vector<string>res;
            for(int i=0;i<temp.size();i++)
            {
                res.push_back(strs[temp[i]]);
            }
            ans.push_back(res);
        }
        return ans;*/
        for(int i=0;i<n;i++)
        {
           string temp=getone(strs[i]);
           mp[temp].push_back(strs[i]);
        }
        for(auto it:mp)
        {

            ans.push_back(it.second);
        }
        return ans;
    }
};
