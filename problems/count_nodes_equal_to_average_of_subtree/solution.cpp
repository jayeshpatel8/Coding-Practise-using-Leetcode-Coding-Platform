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
    int averageOfSubtree(TreeNode* root) {
        avg(root);
        return ans;
    }
    array<int,2> avg(TreeNode* root) {
        if (!root) return {0,0};
        auto l = avg(root->left);
        auto r = avg(root->right);
        int sum =  root->val + l[0] + r[0];
        int cnt =  1 + l[1] + r[1];
        if ((sum/cnt) == root->val) ans++;
        return {sum, cnt};
    }
};