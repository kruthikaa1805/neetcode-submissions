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
    int height(TreeNode* root)
    {
       
        if(root->left==NULL && root->right==NULL)
        return 1;
        int ls=0;
        if(root->left!=NULL)
        ls=height(root->left);
        int rs=0;
        if(root->right!=NULL)
        rs=height(root->right);
        if(ls==-1 || rs==-1)
        return -1;
        if(abs(ls-rs)>1)
        return -1;
        return max(ls,rs)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        return true;
        int ans=height(root);
        if(ans==-1)
        return false;
        return true;
    }
};
