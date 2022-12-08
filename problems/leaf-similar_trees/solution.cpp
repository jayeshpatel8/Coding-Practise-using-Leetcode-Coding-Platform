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
    vector<int> leaf,leaf2;
    int i = 0 , N = 0;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        N = leaf.size();
       if (!dfs2(root2)) return false;
       return i == N;        
    }
    void dfs(TreeNode* root){
        if (!root) return;
        if (root->left == root->right){
            leaf.push_back(root->val); return;
        }
        dfs(root->left);
        dfs(root->right);
    }
    int dfs2(TreeNode* root){
        if (!root) return true;
        if (root->left == root->right){
            return (N > i && leaf[i++] == root->val);
        }
        if (!dfs2(root->left) || !dfs2(root->right)) return false;
        return true;
    }    
};