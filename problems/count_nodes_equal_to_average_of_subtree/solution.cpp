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
int ans = 0;
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0,0};
        auto [s1,c1] = dfs(root->left);
        auto [s2,c2 ] = dfs(root->right);

        int sum = s1+s2+root->val ,cnt= c1+c2+1;
        if ((sum) / (cnt) == root->val){
            ans++;
        }
        return {sum,cnt};
    }
};