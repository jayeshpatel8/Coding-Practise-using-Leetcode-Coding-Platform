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
    int prev=INT_MIN, cnt=0, fmax=0;
    vector<int> findMode(TreeNode* root) {
        if (!root) return ans;
        findMode(root->left);
        if (prev == root->val) cnt++;
        else cnt=1;

        if (cnt > fmax){
            ans.clear();
            fmax=cnt;
            ans.push_back(root->val);
        }
        else if(cnt == fmax){
            ans.push_back(root->val);
        }
        prev = root->val;
        findMode(root->right);
        return ans;
    }
};