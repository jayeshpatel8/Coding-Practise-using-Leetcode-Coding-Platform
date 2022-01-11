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
    int sumRootToLeaf(TreeNode* root, int n=0) {
        if (!root) return 0;
        n = (n << 1) + root->val;
        if (root->left || root->right){
            sumRootToLeaf(root->left,n);
            sumRootToLeaf(root->right,n);
        }
        else
            ans += n;
        return ans;
    }
};