class Solution {
public:
     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            pair<string,int>p=q.front();
            string word=p.first;
            int steps=p.second;
            q.pop();
            if(word==endWord)
            return steps;
            steps++;
            for(int i=0;i<word.size();i++)
            {
                char original=word[i];
                //original is h;
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                    st.erase(word);
                    q.push({word,steps});
                    }
                }
                word[i]=original;
            }
           
        }
         return 0;
    }
};
