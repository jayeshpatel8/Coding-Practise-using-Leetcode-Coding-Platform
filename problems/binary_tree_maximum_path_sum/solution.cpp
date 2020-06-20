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
    int m=INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxPathSum_(root);
        return m;
    }
    int maxPathSum_(TreeNode* root) {
        if (!root) return 0;

        int l = (maxPathSum_(root->left));
        int r = (maxPathSum_(root->right));
        int a = root->val;
        int big= max(a,a+max(r,l));
        m = max(m,max(a+r+l,big));

     return big;
    }

};