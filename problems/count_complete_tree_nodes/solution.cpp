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
    int height(TreeNode * root){
        if (!root) return 0;
        int cnt = 0;
        while (root)
            cnt++,    root=root->left;
        return cnt;
    }
    int countNodes(TreeNode* root,int cnt = 1) {
        if (!root) return 0;
        auto lh = height(root->left) , rh = height(root->right);

        if (rh==0)
            return lh == 0 ? cnt : cnt *2;
        else{
            if (lh==rh) return countNodes(root->right,cnt* 2 + 1);
            else return countNodes(root->left,cnt*2);
        }
    }
};