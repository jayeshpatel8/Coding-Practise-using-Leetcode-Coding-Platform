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
    TreeNode* cur;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode ans;
        cur = &ans;
        dfs(root);
        return ans.right;
    }
    void dfs(TreeNode* root){
        if (!root) return;
        dfs(root->left);
        cur->right = root;
        cur = root;
        root->left=NULL;
        dfs(root->right);
    }
};