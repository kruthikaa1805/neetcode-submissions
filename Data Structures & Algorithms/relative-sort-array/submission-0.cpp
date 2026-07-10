class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr1[j]==arr2[i])
                ans.push_back(arr1[j]);
            }
        }
        vector<int>rem;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr1[i]==arr2[j])
                break;
                if(j==m-1 && arr1[i]!=arr2[j])
                rem.push_back(arr1[i]);
            }
            
        }
        sort(rem.begin(),rem.end());
        int k=rem.size();
        for(int i=0;i<k;i++)
        {
            ans.push_back(rem[i]);
        }
        return ans;
    }
};