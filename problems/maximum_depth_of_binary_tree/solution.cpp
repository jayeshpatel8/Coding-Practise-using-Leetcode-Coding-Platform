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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        while (!q.empty()){
            int sz = q.size();
            while (sz-- > 0){
                auto n = q.front(); q.pop();
                if (n->right) q.push(n->right);
                if (n->left) q.push(n->left);
            }
            depth++;
        }
        return depth;
    }
};