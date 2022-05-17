/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans = NULL;
    TreeNode* getTargetCopy(TreeNode* ori, TreeNode* clo, TreeNode* tar) {
        if (!ori || ans) return ans;
        if (ori == tar) return ans = clo;
        getTargetCopy(ori->left, clo->left, tar);
        getTargetCopy(ori->right, clo->right, tar);
        return ans;
    }
};