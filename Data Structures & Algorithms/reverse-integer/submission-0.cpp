class Solution {
public:
    int reverse(int x) {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int res=0;
        while(x!=0)
        {
            int digit=x%10;
            if(res>maxi/10 || (res==maxi/10 && digit>maxi%10))
            return 0;
            else if(res<mini/10 || (res==mini/10 && digit<mini%10))
            return 0;
            res=res*10+digit;
            x=x/10;
        }
        return res;
    }
};
