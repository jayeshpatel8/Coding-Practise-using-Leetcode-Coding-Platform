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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) return root1 == root2;
        if (root1->val != root2->val) return false;
        //if (root1->left  && root2->left && (root1->left->val == root2->left->val)){
            auto l =    flipEquiv (root1->left, root2->left);
            auto r =    flipEquiv (root1->right, root2->right);
          
        if (r && l) return true;
        {
            auto l =    flipEquiv (root1->left, root2->right);
            auto r =    flipEquiv (root1->right, root2->left);
            return l && r;
        }
        
    }
};
