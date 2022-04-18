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
    int cnt=1, ans;
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return ans;
        kthSmallest(root->left,k);
        if (k==cnt++) ans=root->val;
        kthSmallest(root->right,k);
        return ans;
    }
};