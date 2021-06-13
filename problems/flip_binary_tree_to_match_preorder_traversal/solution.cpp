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
    vector<int> ans;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        int i=0;
        ans.clear();
        return pre(root, v,i) ? ans : vector<int>{-1};
    }
    bool pre(TreeNode* root, vector<int>& v, int & i){
        if(!root) return true;
        if (root->val != v[i]) return false;
        
        i++;
        if (pre(root->left, v,i)){
            return pre(root->right, v,i);
        }
        ans.push_back(v[i-1]);
        return pre(root->right, v,i) && pre(root->left, v,i);
    }
};