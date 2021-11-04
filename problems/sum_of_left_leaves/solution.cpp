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
    int ans=0;
    int sumOfLeftLeaves(TreeNode* root, bool left = 0) {
        if (!root) return ans;
        if (left && !root->left && !root->right )  {ans +=root->val;
                                                    return ans;
                                                   }
        
        sumOfLeftLeaves(root->left, 1);
        sumOfLeftLeaves(root->right, 0);
        
        return ans;
    }
};