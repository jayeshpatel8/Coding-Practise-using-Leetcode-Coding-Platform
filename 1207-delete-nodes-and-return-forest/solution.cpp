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
    vector<TreeNode*>   ans;
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st (begin(to_delete), end(to_delete));
        if (root && !st.count(root->val)) ans.push_back(root);
        dfs(root,st);
        return ans;
    }
    TreeNode*  dfs(TreeNode* root, unordered_set<int>& st) {
        if (!root || st.empty())    return root;
        auto to_delete = root->val;

        root->left = dfs(root->left,st);
        root->right = dfs(root->right,st);
        if (st.count(to_delete )){
            st.erase(to_delete);
            if ( root->left)  ans.push_back(root->left);
            if ( root->right) ans.push_back(root->right);
            delete root;
            return nullptr;
        }
        return root;
    }
};
