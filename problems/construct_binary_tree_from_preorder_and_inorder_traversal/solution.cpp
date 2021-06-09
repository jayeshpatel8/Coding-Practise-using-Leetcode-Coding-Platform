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
    int idx=0;
    unordered_map<int,int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for (int i=0; i< preorder.size(); i++) map[inorder[i]]=i;
        return bt(preorder, 0,preorder.size()-1);
    }
    
    TreeNode* bt(vector<int>& pre, int  left, int right) {
       
        if (left > right) return 0;
        TreeNode * root = new TreeNode(pre[idx++]);
        int mid = map[root->val];
        root->left = bt(pre,left, mid-1);
        root->right = bt(pre,mid+1,right);
        return root;
    }
};