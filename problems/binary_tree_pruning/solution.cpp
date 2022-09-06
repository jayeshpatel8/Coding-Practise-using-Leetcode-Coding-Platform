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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root->val || root->left || root->right ? root: NULL;
    }
    TreeNode* pruneTree2(TreeNode* root) {
        if (!dfs(root)) return 0;
        dfs(root);
        return root;
    }
    int dfs(TreeNode * root){
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (!l) root->left = NULL;
        if (!r) root->right = NULL;
        return root->val | l | r;
    }
};