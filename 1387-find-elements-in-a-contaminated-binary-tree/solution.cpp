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
class FindElements {
public:
    unordered_set<int> ust;
    FindElements(TreeNode* root) {
        root->val=0;
        dfs(root);
    }
    
    bool find(int target) {
        return ust.count(target);
    }
    void dfs(TreeNode * root){
        if (!root) return ;
        int v = root->val;
        ust.insert(v);
        if (root->left) root->left->val = 2 * v +1;
        if (root->right) root->right->val = 2 * v +2;
        dfs(root->left);
        dfs(root->right);

    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
