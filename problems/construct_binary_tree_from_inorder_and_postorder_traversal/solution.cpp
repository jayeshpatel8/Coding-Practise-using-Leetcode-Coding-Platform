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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()<1) NULL;
        unordered_map<int,int> map;
        for (int i=0; i<inorder.size(); i++)
            map[inorder[i]]=i;
        idx=inorder.size()-1;
        return buildTree(inorder, postorder ,  map, 0, inorder.size()-1);
    }
   TreeNode* buildTree(vector<int>& in, vector<int>& po , unordered_map<int,int> & map, int st, int en)   {
       if(st>en) return NULL;
       int val =po[idx--];
       TreeNode*root = new TreeNode(val);
       if (st==en) return root;
       int i = map[val];
       root->right = buildTree(in, po,  map, i+1,en);
       root->left = buildTree(in, po,  map, st,i-1);
       return root;
       
   }
};