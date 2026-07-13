class Solution {
public:
    double helper(double x,int n)
    {
        if(n==0)
        return 1;
        else if(n%2==0)
        {
            return helper(x*x,n/2);
        }
        else
        return x*helper(x,n-1);
    }
    double myPow(double x, int n) {
        int N=n;
        if(n<0)
        {
            N=-n;
            double ans=helper(x,N);
            return (1/ans);
        }
        return helper(x,n);
    }
};
