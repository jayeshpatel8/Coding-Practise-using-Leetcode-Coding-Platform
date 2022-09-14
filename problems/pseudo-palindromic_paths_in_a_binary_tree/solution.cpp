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
    //int freq=0;
    int pseudoPalindromicPaths (TreeNode* root, int freq = 0) {
        if (!root) return ans ;

        freq ^= (1<<root->val);
        if (!root->left && !root->right){
            ans += (freq & (freq-1))==0;
        }
        else{
            pseudoPalindromicPaths(root->left,freq);
            pseudoPalindromicPaths(root->right,freq);
        }
        //freq ^= (1<<root->val);
        return ans;
    }
};