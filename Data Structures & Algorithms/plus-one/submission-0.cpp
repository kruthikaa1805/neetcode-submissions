class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>ans;
        bool flag=false;
        for(int i=n-1;i>=0;i--)
        {
            int val=digits[i];
            if(i==n-1 || flag==true)
            {
                val=val+1;
            }
           if(val>9)
           {
            flag=true;
            val=val%10;
            ans.push_back(val);
           }
           else
           {
            flag=false;
            ans.push_back(val);
           }
           
           
        }
        if(flag==true)
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
