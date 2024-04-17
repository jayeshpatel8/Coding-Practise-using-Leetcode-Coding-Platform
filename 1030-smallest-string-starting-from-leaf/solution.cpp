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
    string ans,s;
    
    string smallestFromLeaf(TreeNode* root) {
        if (!root->left && !root->right) {
            int ch =root->val + 'a';
            s.push_back(ch);
            string s1(rbegin(s),rend(s));
            s.pop_back();
            if (ans.empty()) return ans = s1;
            if (ans > s1) ans =s1;
            return ans;
        }
        s += root->val+'a';
        if (root->left )
            smallestFromLeaf(root->left );
        if (root->right)
            smallestFromLeaf(root->right);
        s.pop_back();
        return ans;
    }
};
