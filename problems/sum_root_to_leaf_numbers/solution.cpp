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
int sum = 0;
    int sumNumbers(TreeNode* root, int i=0) {
        if (!root) return (sum +=i);
        auto s = i*10 + root->val;
        if(root->left)
            sumNumbers(root->left,s);
        if (root->right)
            sumNumbers(root->right,s);
        if (!root->left && !root->right) 
            sum += s;
        return sum;
    }
};