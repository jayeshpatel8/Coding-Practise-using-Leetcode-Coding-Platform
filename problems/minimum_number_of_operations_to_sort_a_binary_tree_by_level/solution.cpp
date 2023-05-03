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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()){
            int sz = q.size();
            vector<int> v;
            while(sz-- > 0){
                auto *r = q.front();q.pop();
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
                v.push_back(r->val);
            }
            vector<int> ids(v.size());
            iota(begin(ids),end(ids),0);
            sort(begin(ids),end(ids),[&](auto a, auto b){return v[a] < v[b];});
            
            for (int i=0; i<ids.size(); i++){
                for (; ids[i] != i ; )
                    swap(ids[i],ids[ids[i]]),ans++;
            }
        }
        return ans;
    }
};