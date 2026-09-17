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
    bool helper(TreeNode* root,int mini,int maxi)
    {
       if(root==NULL)
       return true;
       // if(root->val <maxi && root->val > mini)
       // return true;
        if(root->val<= mini || root->val >= maxi)
        return false;
       // if(root->left==NULL && root->right==NULL)
       // return true;
       // bool left=true;
       // if(root->left!=NULL)
       bool left=helper(root->left,mini,root->val);
       // bool right=true;
       // if(root->right!=NULL)
       bool right=helper(root->right,root->val,maxi );
    
        return left && right;
        
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        return true;
        return helper(root,INT_MIN,INT_MAX);
    }
};
