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
    pair<int,int> rob1(TreeNode* root) {
        if (!root)
            return {0,0};
            
        pair<int,int> l , r;
        l = rob1(root->left);
        r = rob1(root->right);
        int without_root = l.first + r.first;
        
        return {max(root->val + l.second + r.second, without_root), l.first + r.first};
    }

    int rob(TreeNode* root) {
        pair<int,int> ans = rob1(root);
        return max(ans.first ,ans.second);
    }
};