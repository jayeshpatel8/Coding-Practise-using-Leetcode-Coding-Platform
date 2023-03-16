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
unordered_map<int,int> map;
int  i ;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i=0;  i<inorder.size(); i++) map[inorder[i]]=i;
    i = postorder.size()-1;
        return dfs(inorder, postorder, 0,postorder.size()-1);
    }
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder,int l, int r){
        if (r<l ) return nullptr;
        auto * n = new TreeNode(postorder[i]);
        int m = map[postorder[i--]];
        n->right = dfs(inorder, postorder,m+1,r);
        n->left = dfs(inorder, postorder,l ,m-1);
        return n;
    }
};