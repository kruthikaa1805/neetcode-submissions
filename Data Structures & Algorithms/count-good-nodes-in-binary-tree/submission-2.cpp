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
    int cnt=0;
    void helper(TreeNode* root,int maxi)
    {
        if(root==NULL)
        return;
        if(root->val==maxi)
        cnt++;
        if(root->left!=NULL)
        helper(root->left,max(maxi,root->left->val));
        if(root->right!=NULL)
        helper(root->right,max(maxi,root->right->val));
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)
        return 0;
        helper(root,root->val);
        return cnt;
    }
};
