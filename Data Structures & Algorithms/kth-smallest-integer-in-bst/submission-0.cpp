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
    int kthSmallest(TreeNode* root, int k) {
         int cnt=0;
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
                curr=st.top();
                st.pop();
                cnt++;
                if(cnt==k)
                return curr->val;
                curr=curr->right;
            }
         }
         return -1;
    }
};
