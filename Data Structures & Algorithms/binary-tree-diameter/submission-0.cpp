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
    
    int getheight(TreeNode* root,int & max_dia)
    {
        if(root==NULL)
        return 0;
        int lh=getheight(root->left,max_dia);
        int rh=getheight(root->right,max_dia);
        max_dia=max(max_dia,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        return 0;
        int max_dia=0;
        getheight(root,max_dia);
        return max_dia;

    }
};
