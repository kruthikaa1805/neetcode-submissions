class Solution {
public:
    bool checkValidString(string s) {
        int mini=0;
        int maxi=0;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
            mini++;
            maxi++;
            }
            else if(ch==')')
            {
                mini--;
                maxi--;
            }
            else
            {
                mini--;
                maxi++;
            }
            if(mini<0)
            mini=0;
            if(maxi<0)
            return false;
           
        }
        if(mini==0 && maxi>=0)
        return true;
        else
        return false;
    }
};
