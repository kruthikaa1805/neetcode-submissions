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
    int getheight(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        int lh=getheight(root->left);
        int rh=getheight(root->right);
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        return true;
        int lh=getheight(root->left);
        int rh=getheight(root->right);
        if(abs(lh-rh)>1)
        return false;
        else 
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
