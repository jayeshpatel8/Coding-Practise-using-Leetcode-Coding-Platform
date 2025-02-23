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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return construct(pre,post,0,pre.size()-1);;
    }
    // pre  = [1,2,4,5,3,6,7], 
    // post = [4,5,2,6,7,3,1]    
    TreeNode* construct(vector<int>& pre, vector<int>& post, int s, int e){
        
        if(s>e) return NULL;
        TreeNode * root = new TreeNode(pre[idx++]);
        
        if (s==e) return root;
        
        int i = s;
        while(pre[idx] != post[i]) i++;
        
        root->left = construct(pre,post,s,i);
        root->right = construct(pre,post,i+1,e-1);
        return root;
    }
};
