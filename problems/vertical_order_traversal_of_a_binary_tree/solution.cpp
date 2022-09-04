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
    map<pair<int,int>,vector<int>> map1;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        preorder(root,0,0);
        vector<vector<int>> ans;
        map<int,vector<int>> map2;
        for (auto &[k,v] : map1){
            sort(begin(v),end(v));    
            for (auto e : v)
                map2[k.second].push_back(e);
        }
        for (auto &[k,v] : map2){
            ans.push_back(v);
        }

        return ans;
    }
    void preorder(TreeNode * root, int r, int c){
        if (!root) return;
        map1[{r,c}].push_back(root->val);
        preorder(root->left,r+1,c-1);
        preorder(root->right,r+1,c+1);
    }
};