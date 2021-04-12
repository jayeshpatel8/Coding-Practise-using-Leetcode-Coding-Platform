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
    int  max_cnt=0,sum=0;
    int deepestLeavesSum(TreeNode* root) {
        dls(root,0);
        
        return sum;
    }
    void dls(TreeNode * root, int cnt){
        if (!root){
            if (cnt>max_cnt) 
            {  max_cnt =cnt ; sum = 0;}
            return ;
        }
        cnt++;
        dls(root->left,cnt);
        dls(root->right,cnt);
        
        if (cnt == max_cnt) sum +=root->val;
    }
};