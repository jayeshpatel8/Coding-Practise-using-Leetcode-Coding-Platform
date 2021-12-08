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
    int sum = 0;
    int findTilt(TreeNode* root) {
        findT(root);
        return sum;
    }
    int findT(TreeNode* root) {
        if (!root) return 0;
        int l = findT(root->left), r = findT(root->right);
        sum += abs(l-r);
        return root->val + l + r;
    }
};