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
    int sum=0;
public:
    int sumNumbers(TreeNode* root) {
         sumNumbers(root,0);
        return sum;
    }
    void sumNumbers(TreeNode* root,int n){
        if (!root) {return;}
        n =n*10+root->val;
         if(!root->left && !root->right)
             {sum+=n;return;}
        
        sumNumbers(root->right,n);
        
        sumNumbers(root->left,n);
        
    }
};