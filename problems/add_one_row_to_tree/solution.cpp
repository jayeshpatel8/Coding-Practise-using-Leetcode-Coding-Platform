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
        if (depth == 1){
            TreeNode *r  = new TreeNode(val);
            r->left = root;
            return r;
        }
        queue<TreeNode*> q;
        int d=2;
        q.push(root);
        while (d <=depth){
            if (d == depth){
                int sz = q.size();
                while (sz-->0){
                    auto * n = q.front(); q.pop();
                    auto * l = new TreeNode (val);
                    auto * r = new TreeNode (val);
                    l->left = n->left;
                    r->right = n->right;
                    n->left = l;
                    n->right = r;
                }
                
            }
            else{
                int sz = q.size();
                while (sz-->0){
                    auto n = q.front(); q.pop();
                    if (n->left)
                        q.push(n->left);
                    if (n->right)
                        q.push(n->right);
                }
            }
            d++;
        }
        return root;
    }
};