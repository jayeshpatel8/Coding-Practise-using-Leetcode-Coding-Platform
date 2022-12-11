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
int ans= INT_MIN ;
    int maxPathSum(TreeNode* root) {
       dfs2(root);
       return ans;
    }

    int dfs2(TreeNode * root){
        if (!root) return 0 ;
        int lsum = dfs2(root->left);
        int rsum = dfs2(root->right);
        int best = root->val + max({0 , lsum,rsum});

        ans = max({ans,best, root->val  + lsum + rsum});
        return best ;
    }
};