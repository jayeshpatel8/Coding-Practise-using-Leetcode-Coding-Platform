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
    int maxAncestorDiff(TreeNode* root) {
        findMinMax(root,root->val,root->val);
        return ans;
    }
    void findMinMax(TreeNode * root, int  mi, int  ma){
        if (!root) 
            return ;
        mi = min(mi,root->val); 
        ma = max(ma,root->val);
        ans= max(ans, ma-mi);
        findMinMax(root->left,mi,ma);
        findMinMax(root->right,mi,ma);
    }
};