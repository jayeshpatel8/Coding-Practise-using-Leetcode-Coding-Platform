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
    int goodNodes(TreeNode* root, int cmax = INT_MIN) {
        if (!root) return 0;
        int cnt = root->val >= cmax;
        if  (cnt) cmax =  root->val;
        cnt += goodNodes(root->left,cmax);
        cnt += goodNodes(root->right, cmax);
        return cnt;
    }
};