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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;        
        q.push(root);
        bool nochild = false;
        while (!q.empty()){
            int sz = q.size();
            while (sz-- > 0 ){
                auto n = q.front(); q.pop();
                if (n) {
                    if (nochild) return false;

                    q.push((n->left));

                    q.push((n->right));                    
                }
                else 
                    nochild=true;

            }
        }
        return true;
    }
};