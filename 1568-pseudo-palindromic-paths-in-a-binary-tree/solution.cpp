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
    unsigned int ans=0;
    int f[10]={};
    int pseudoPalindromicPaths (TreeNode* root, int odd=0) {
        if (!root) {
            
            return ans;
        }
        if ((f[root->val]++ & 1) == 0 ) odd++;
        else odd--;

        pseudoPalindromicPaths(root->left,odd);
        pseudoPalindromicPaths(root->right,odd);
        if (!root->left && !root->right) ans += odd<=1;
        f[root->val]--;
        return ans;
    }
};
