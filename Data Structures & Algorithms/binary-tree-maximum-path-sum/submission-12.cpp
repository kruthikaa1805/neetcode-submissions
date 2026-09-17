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
    int sum=INT_MIN;
    int helper(TreeNode* root)
    {
        // if(root==NULL)
       // return 0;
       
       int ls=0;
       if(root->left!=NULL)
         ls=max(0,helper(root->left));
         int rs=0;
         if(root->right!=NULL)
        rs=max(0,helper(root->right));
        int opt1=ls+rs+root->val;
        sum=max(sum,opt1);
        return root->val+max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
        return 0;
         if(root->left==NULL && root->right==NULL)
        return root->val;
          helper(root);
          return sum;


    }
};
