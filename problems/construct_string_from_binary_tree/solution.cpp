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
    string tree2str(TreeNode* r) {
        string s = to_string(r->val);
        
        if (r->left){
            s += '(' + tree2str(r->left) + ')';
        }
        if (r->right){
            if (r->left == NULL)  s += "()";
            s += '(' + tree2str(r->right) + ')';
        }
        return s;
        
    }

};