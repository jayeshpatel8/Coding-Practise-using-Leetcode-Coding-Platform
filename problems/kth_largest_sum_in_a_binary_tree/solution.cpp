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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        using ll = long long;
        priority_queue<ll> pq;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            ll  sum = 0;
            while (sz-- > 0){
                auto i = q.front(); q.pop();
                sum += i->val;
                if (i->right) q.push(i->right);
                if (i->left) q.push(i->left);
            }
            pq.push(sum);
        }
        if (k > pq.size()) return -1;
        while (k > 1 ) {
            --k; pq.pop();
        }
        return pq.top();
    }
};