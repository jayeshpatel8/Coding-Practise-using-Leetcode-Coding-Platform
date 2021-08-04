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
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxsum(root);
        return ans;
    }
    int maxsum(TreeNode* root){
        if (!root) return 0;
        int lsum = maxsum(root->left);
        int rsum = maxsum(root->right);
        int big = max ({root->val, root->val + max(lsum,rsum),root->val });
        ans = max({ans , big , root->val + lsum + rsum});
        return big;
    }
};