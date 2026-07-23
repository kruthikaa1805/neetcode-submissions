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
        TreeNode*  prev_val=NULL;
        TreeNode* curr=root;
        stack<TreeNode*>st;
        
        while(!st.empty() || curr!=NULL)
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode* temp=st.top();
            st.pop();
            if(prev_val!=NULL &&temp->val <= prev_val->val)
            return false;
            else
            {
                prev_val=temp;
            }
            curr=temp->right;
            }
           

        }
        return true;
    }
};
