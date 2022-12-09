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
    int maxAncestorDiff(TreeNode* root,  int max_=0, int min_ = 1e5) {
        if (!root){
            return ans;
        }
        if (max_ < root->val)
            max_ = root->val;
        if (min_ > root->val)
            min_ = root->val;
        if (!root->left && !root->right){
            return ans = max(ans, (max_ - min_)); 
        }
        maxAncestorDiff(root->left,max_,min_);
        maxAncestorDiff(root->right,max_,min_);
        return ans;
    }
};