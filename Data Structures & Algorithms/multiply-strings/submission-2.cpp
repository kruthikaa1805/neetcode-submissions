class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
        return "0";
        int n=num1.length();
        int m=num2.length();
        vector<int>ans(n+m,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
               int digit1=num1[i]-'0';
               int digit2=num2[j]-'0';
               int prod=digit1*digit2;
               int sum=prod+ans[i+j+1];

               ans[i+j+1]=sum%10;
               ans[i+j]+=sum/10;
            }
        }
        string res="";
        for(int num:ans)
        {
            if(!res.empty() || num!=0)
            {
               
             res+=to_string(num);
            }
            
        }
        return res;
    }
};
