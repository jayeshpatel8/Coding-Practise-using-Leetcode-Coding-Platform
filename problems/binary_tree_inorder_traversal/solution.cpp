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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> st;
        st.push(root);
        vector<int> ans;
        while (!st.empty()){
            auto * r = st.top();
            if (!r->left){
                ans.push_back(r->val); st.pop();
                if (r->right) st.push(r->right);
            }
            else{
                st.push(r->left); 
                r->left=NULL;
            }
        }
        return ans;
    }
};