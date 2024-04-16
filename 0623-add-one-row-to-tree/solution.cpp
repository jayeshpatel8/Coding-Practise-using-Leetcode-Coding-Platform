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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode *r = new TreeNode(val,root,nullptr);
            return r;
        }
        dfs(root,val, depth, 1);
        return root;
    }
    TreeNode * dfs(TreeNode * r, int val, int d, bool l){
        d--;
        if (d == 0){
            TreeNode *root = new TreeNode(val);
            if (l)
                root->left = r;
            else root->right = r;
            return root;
        }
        if (!r) return r;
        r->left = dfs(r->left,val,d,1);
        r->right = dfs(r->right,val,d,0);
        return r;
        
    }
};
