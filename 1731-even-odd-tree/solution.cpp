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
    bool isEvenOddTree(TreeNode* root) {
        vector<TreeNode *> q{root};
        bool odd=true;
        
        while (!q.empty()){
            vector<TreeNode *> t;
            if (odd){
                int prev = 0;
                for (auto r : q){
                    if (r->val <= prev || (r->val &1)==0 ) return false;
                    prev = r->val;
                    if (r->left) t.push_back(r->left);
                    if (r->right) t.push_back(r->right);
                }                    
            }
            else{
                int prev = INT_MAX;
                for (auto r : q){
                    if (r->val >= prev || (r->val &1)) return false;
                    prev = r->val;
                    if (r->left) t.push_back(r->left);
                    if (r->right) t.push_back(r->right);
                }                    
            }
            odd = !odd;
            t.swap(q);
        }
        return true;
    }
};
