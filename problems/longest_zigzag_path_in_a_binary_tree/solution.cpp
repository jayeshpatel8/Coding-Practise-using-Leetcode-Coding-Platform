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
    int longestZigZag(TreeNode* root) {
        return max(dfs(root->right,'r',0),dfs(root->left,'l',0));
    }
    int dfs(TreeNode* root, int d, int len){
        if (!root) return len;
        return max (dfs(root->left,'l',d=='r' ? len+1 : 0 ),dfs(root->right,'r',d=='l' ?len+1 :0 ));
    }
};