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
unordered_map<int, int> sum;
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs(root,0);
        dfs2(root,0);
        root->val=0;
        return root;
    }
    void dfs(TreeNode * r, int height){
        if (!r) return;
        sum[height] += r->val;
        dfs(r->left,height+1);
        dfs(r->right,height+1);
    }
    int dfs2(TreeNode *r, int h){
        if (!r) return 0;
        int v = dfs2(r->left,h+1) + dfs2(r->right, h+1);
        if (r->left){
            r->left->val =  sum[h+1]-v;
        }
        if (r->right){
            r->right->val =  sum[h+1]-v;
        }
        return r->val;
    }
};