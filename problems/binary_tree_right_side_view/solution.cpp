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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> a;
        if (!root) return ans;
        
        a.push_back(root);
        while (!a.empty()){
            ans.push_back(a.back()->val);
            vector<TreeNode*> t;
            for (auto &r : a){
                if (r->left)
                    t.push_back(r->left);
                if (r->right)
                    t.push_back(r->right);
            }
            a.swap(t);
        }
        return ans;
    }
};