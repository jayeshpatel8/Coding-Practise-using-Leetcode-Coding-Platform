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
int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        dfs(root,root->val,root->val);
        return ans;
    }
    void dfs(TreeNode * root, int mi, int ma){
        if (!root) return;
        
        ans = max({abs(mi-root->val), abs(ma-root->val), ans});
        mi = min(mi,root->val);
        ma = max(ma,root->val);
        
        dfs(root->left,mi,ma);
        dfs(root->right,mi,ma);
    }
};
