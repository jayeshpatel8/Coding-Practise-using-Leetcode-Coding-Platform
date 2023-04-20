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
        vector<pair<TreeNode*,size_t>> q{{root,0}};
        size_t ans = 0;
        while (!q.empty()){
            vector<pair<TreeNode*,size_t>> t;
            auto l = q.front().second, r= q.back().second; 
            for (auto &[i,c] : q){
                if (i->left) t.push_back({i->left, 2*c});
                if (i->right) t.push_back({i->right, 2*c+1});
            }

            ans = max(ans, r-l+1);
            q.swap(t);
        }        
        return ans;
    }
    
};