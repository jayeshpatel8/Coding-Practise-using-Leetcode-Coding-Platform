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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,size_t>> q;
        q.push({root,1});
        size_t ans = 0;
        while(!q.empty()){
            int sz = q.size();
             auto l = q.front().second, r= q.back().second;            
            while(sz--){
                auto root = q.front().first;
                auto num  = q.front().second;
                if (root->left) q.push({ root->left, num*2});
                if (root->right) q.push({root->right,num*2 + 1});
                
                q.pop();
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    } 
};