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
    int sumOfLeftLeaves(TreeNode* root, bool l =false) {
        if (!root) return sum;
        
        if (l && !root->left && !root->right) sum += root->val;
        sumOfLeftLeaves(root->left, true);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};
