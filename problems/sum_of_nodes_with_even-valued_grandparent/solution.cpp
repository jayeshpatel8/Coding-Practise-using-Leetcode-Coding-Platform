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
    int ans=0;
    int sumEvenGrandparent(TreeNode* root,int p=1, int g=1) {
        if (root){
            int v = root->val;
            if (g%2 == 0)
                ans += v;                
            sumEvenGrandparent(root->left,v,p);
            sumEvenGrandparent(root->right,v,p);
        }
        return ans;
    }
};