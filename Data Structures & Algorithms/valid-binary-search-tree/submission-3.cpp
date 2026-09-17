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
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        return true;
        int prev=INT_MIN;
        stack<TreeNode*>st;
        TreeNode* curr=root;
        while(!st.empty()||curr!=NULL)
        {
             if(curr!=NULL)
             {
                st.push(curr);
                curr=curr->left;
             }
             else
             {
            curr=st.top();
             st.pop();
             if(curr->val <= prev)
             return false;
             prev=curr->val;
             curr=curr->right;
             }   

        }
        return true;
    }
};
