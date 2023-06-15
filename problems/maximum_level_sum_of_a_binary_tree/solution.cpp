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
int N = -1;
vector<int> sum;
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode *> q{root};
        int s=INT_MIN,ans = 0,l=1;
        while (!q.empty()){
            vector<TreeNode *> t;
            int s1=0;
            for (auto r : q){
                s1 += r->val;

                if(r->left) t.push_back(r->left);
                if(r->right) t.push_back(r->right);
            }
            q.swap(t);
            if (s < s1)
                s=s1, ans=l;
            l++;
        }
        return ans;
    }
    int maxLevelSum2(TreeNode* root) {
        dfs(root,0);
        vector<int> id(sum.size());
        iota(begin(id),end(id),0);
        sort(begin(id), end(id),[&](int a, int b){ return sum[a] == sum[b] ? a <b : sum[a] > sum[b]; });
        return id[0] + 1;
    }
    void dfs(TreeNode * r,int i){
        if (!r) return;
        if (N<i) sum.push_back(r->val), N++;
        else sum[i]+=r->val;
        dfs(r->left, ++i);
        dfs(r->right, i);
    }
};