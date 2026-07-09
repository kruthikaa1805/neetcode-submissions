class Solution {
public:
//expand around the centre;
//at every index asume it to be the centre and find the length of max palindrome possible
   int helper(string s,int i,int j)
   {
    int n=s.length();
    while(i>=0 &&j<n)
    {
        if(s[i]==s[j])
        {
            i--;
        j++;
        }
       
        else
        break;
    }
    return j-i-1;
   }
    string longestPalindrome(string s) {
         int n=s.length();
         int max_length=1;
         int start=0;
         for(int i=0;i<n;i++)
         {
            int odd=helper(s,i,i);
            int even=helper(s,i,i+1);
            int curr_max=max(odd,even);
            if(curr_max>max_length)
            {
                max_length=curr_max;
                start=i-(curr_max-1)/2;
            }
            
         }
         string ans= s.substr(start,max_length);
         return ans;
    }
};
