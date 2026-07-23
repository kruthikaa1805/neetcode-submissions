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
    void countnodes(TreeNode* root,int maxi,int &cnt)
    {
        if(root==NULL)
        return;
       if(root->val>=maxi)
       {
        maxi=root->val;
        cnt++;
       }
       countnodes(root->left,maxi,cnt);
       countnodes(root->right,maxi,cnt);
       return;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)
        return 0;
        int maxi=INT_MIN;
        int cnt=0;
        countnodes(root,maxi,cnt);
        return cnt;
    }
};
