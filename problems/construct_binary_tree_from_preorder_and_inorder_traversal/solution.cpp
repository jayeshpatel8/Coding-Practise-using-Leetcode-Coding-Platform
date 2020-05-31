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
    int idx =0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()<1) return 0;
        
        unordered_map<int,int> map;
        for (int i =0; i<preorder.size(); i++)
            map[inorder[i]]=i;
      return buildTree_(0,inorder.size()-1,preorder,inorder,map);
    }
    TreeNode* buildTree_(int start, int end, vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>& map) {
        if (start>end) return NULL;
        int val = preorder[idx++];
        TreeNode * root =  new TreeNode (val);
        if (start == end) return root; 
        int  i = map[val];
        root->left = buildTree_(start,i-1,preorder,inorder,map);
        root->right = buildTree_(i+1,end,preorder,inorder,map);
        return root;
    }
};