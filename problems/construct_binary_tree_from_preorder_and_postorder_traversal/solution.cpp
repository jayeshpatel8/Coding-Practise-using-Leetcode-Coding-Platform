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
#if 0
    TreeNode* construct1(vector<int>& pre, vector<int>& post, int l1, int r1, int l2, int r2){
        if (l1 >= r1) return NULL;
        
        TreeNode * root = new TreeNode(pre[l1]);
        
        int i = 0;
        while (l1 + 1 + i <r1){
            if (pre[l1 + 1] == post[l2 + i] ) {
                i++;break;
            }
            i++;
        } 
        root->left = construct(pre,post,l1+1,l1+1+i,l2,l2+i);
        root->right = construct(pre,post,l1+1+i,r1,l2+i,r2-1);
        return root;
    }
#endif    
};