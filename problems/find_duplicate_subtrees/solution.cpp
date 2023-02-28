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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>  cnt;
        vector<TreeNode*> ans;
        function<string(TreeNode*)> dfs = [&](TreeNode * cur)->string{
                if (!cur) return "";
                string s = "(" + dfs (cur->left)
                            + to_string(cur->val)
                            + dfs (cur->right)+ ")";
                if (++cnt[s]==2) ans.push_back(cur);
                return s;
            };
        dfs(root);
        return ans;
    }
};