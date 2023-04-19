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
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
    array<int,2> dfs(TreeNode * root){
        if (!root) return{0,0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int left=0,right=0;
        if (root->left) left = 1 + l[1];
        if (root->right) right = 1 + r[0];
        ans= max({ans,left,right});
        return {left,right};
    }
};