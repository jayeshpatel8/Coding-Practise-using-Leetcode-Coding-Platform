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
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        auto p  = rob1(root);
        return max(p.first,p.second);
    }
    
    pair<int,int> rob1(TreeNode* root) {
        if (root == NULL) return {0,0};
        
        pair<int,int> l = rob1(root->left);
        pair<int,int> r = rob1(root->right);
        /*int prev1 = l.first+r.first; 
        int prev2 = l.second + r.second;*/
        //int cur = max(root->val + prev2, prev1);
        // return {cur, prev1};
        return {max(root->val + l.second + r.second , l.first+r.first), l.first+r.first}; /* {prev1 , prev2}*/
    }    
};