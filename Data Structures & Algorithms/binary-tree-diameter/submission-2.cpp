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
    int max_dia;
    int helper(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        if(root->left==NULL && root->right==NULL)
        {
            return 1;
        }
        int lh=helper(root->left);
        int rh=helper(root->right);
        max_dia=max(max_dia,lh+rh);
        return 1+max(lh,rh);
       
    }
    int diameterOfBinaryTree(TreeNode* root) {
        max_dia=0;
        if(root==NULL)
        return 0;
        helper(root);
        return max_dia;
    }
};
