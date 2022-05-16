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
    int sum = 0, mxlvl=0;
    int deepestLeavesSum(TreeNode* root ,int lvl=0) {
        if (!root) return sum;
        if (mxlvl == ++lvl)
            sum +=root->val;
        else if (mxlvl < lvl) 
            mxlvl = lvl,  sum = root->val;
        
        deepestLeavesSum(root->left,lvl);
        deepestLeavesSum(root->right,lvl);
        return sum;
    }    
    int deepestLeavesSum2(TreeNode* root) {
        vector<TreeNode *> q;
        q.push_back(root);
        int sum=0 ,j=0 , i =1;
        while (j<i){
            auto sz = i; 
            sum = 0;
            while (j<sz){
                auto * n = q[j++];
                sum += n->val;
                if (n->left) q.push_back(n->left), i++;;
                if (n->right) q.push_back(n->right) , i++;;
               
            }
        }
        return sum;
    }
    
};