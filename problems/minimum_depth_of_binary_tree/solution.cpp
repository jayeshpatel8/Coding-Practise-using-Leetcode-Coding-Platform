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
    int minDepth(TreeNode* root) {
        
        if (!root) return 0;
        vector<TreeNode *> q{root};
        int ans = 0;
        while (!q.empty()){
            vector<TreeNode* > t;
            for (auto u : q){
                if (u->left || u->right){
                    if (u->left)
                        t.push_back(u->left);
                    if (u->right)
                        t.push_back(u->right);
                }
                else
                    return ++ans;
            }
            q.swap(t);
            ans++;
        }
        return ans;
    }
};