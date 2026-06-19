class Solution {
public:
    bool isMatching(char a,char b)
    {
        if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'))
        return true;
        return false;
    }
    stack<char>st;
    bool isValid(string s) {
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
            else
            {
                if(!st.empty() && isMatching(st.top(),s[i]))
                st.pop();
                else
                return false;
            }
        }
        if(!st.empty())
        return false;
        return true;
    }
};
