/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(vector<int>& preorder,int start,int end,int &i,unordered_map<int,int>&mp)
    {
        if(start>end)
        return NULL;
        int val=preorder[i];
        i++;
        TreeNode* root=new TreeNode(val);
        int idx=mp[val];
        root->left=helper(preorder,start,idx-1,i,mp);
        root->right=helper(preorder,idx+1,end,i,mp);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n=preorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
       int i=0;
       return helper(preorder,0,n-1,i,mp);
    }
};
