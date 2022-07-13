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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root, int h = 0) {
        if (!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        int len=1;
        while (!q.empty()){
            int sz = len;
            vector<int> a;
            len=0;
            while (sz-- > 0){
                auto root = q.front() ; q.pop();
                a.push_back(root->val);
                if (root->left)
                    q.push(root->left),++len;
                if (root->right)
                    q.push(root->right),++len;
            }
            if (sz)
                ans.push_back(a);
        }
        return ans;
    }
    vector<vector<int>> levelOrder2(TreeNode* root, int h = 0) {
        if (!root) return ans;
        if (ans.size() <= h)
            ans.push_back(vector<int>());
        ans[h].push_back(root->val);
        levelOrder(root->left,++h);
        levelOrder(root->right,h);
        return ans;
    }
};