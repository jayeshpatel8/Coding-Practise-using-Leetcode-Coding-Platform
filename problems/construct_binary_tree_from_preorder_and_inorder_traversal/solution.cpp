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
int i=0 ;
    unordered_map<int,int> M;
    TreeNode* buildTree(vector<int>& Pre, vector<int>& Ino) {
        for (int i=0; i<Pre.size(); i++) M[Ino[i]]=i;
        return buildTree(Pre,Ino,0,Pre.size()-1);
    }
    TreeNode* buildTree(vector<int>& Pre, vector<int>& Ino, int j1,int j2) {
        if (j1>j2  ) return NULL;
        
        int k = M[Pre[i]];
        
        TreeNode* n = new TreeNode(Pre[i++]);
        n->left = buildTree(Pre,Ino,j1,k-1);
        n->right = buildTree(Pre,Ino,k+1,j2);
        return n;
    }
};