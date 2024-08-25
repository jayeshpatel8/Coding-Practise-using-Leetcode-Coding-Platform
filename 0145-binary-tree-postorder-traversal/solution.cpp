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
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        postorderTraversal_(root);
        return res;
    }
    void postorderTraversal_(TreeNode* root){
        if (!root) return;
        
        postorderTraversal_(root->left);
        postorderTraversal_(root->right);
        res.push_back(root->val);
    }
};
