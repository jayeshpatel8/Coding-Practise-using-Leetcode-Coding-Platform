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
    TreeNode* reverseOddLevels(TreeNode* root) {
        auto * r =root;
        vector<TreeNode *> q {root};
        bool odd=true;
        while (!q.empty()){
            odd = !odd;
            int sz= q.size(), i = 0, j=sz-1;
            vector<TreeNode *> q2;
            {
                while (i <sz){
                    auto * root = q[i];
                    
                    if (odd  &&i<j){
                        swap(q[i]->val , q[j--]->val);
                    }
                    if (root->left){
                        q2.insert(end(q2),root->left);
                        q2.insert(end(q2),root->right);
                    }
                    i++;
                }
            }
            q.swap(q2);
        }
        return r;
    }
    TreeNode* reverseOddLevels2(TreeNode* root) {
        auto * r =root;
        vector<TreeNode *> q;
        q.push_back(root);
        bool odd=false;
        while (!q.empty()){
            odd = !odd;
            int sz= q.size(), i = 0;
            vector<TreeNode *> q2;
            if (q[0]){
                while (i <sz){
                    auto * root = q[i++];
                    q2.push_back(root->left);
                    q2.push_back(root->right);
                }
            }
            q.swap(q2);
            if (odd && !q.empty()&& q[0]){
                int i=0,j = 2*sz - 1;
                while (i<j)
                    swap(q[i++]->val,q[j--]->val);
            }
        }
        return r;
    }
};