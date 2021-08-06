/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node *> q;
        q.push(root);
        vector<vector<int>> ans;
        
        while(!q.empty()){
            int sz = q.size();
            vector<int> v;
            while (sz--){
                Node * t = q.front(); q.pop();
                v.push_back(t->val);
                for (auto &c : t->children){
                   q.push(c);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};