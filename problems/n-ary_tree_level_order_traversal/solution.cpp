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
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> A;
            while(sz-- > 0){
                auto r = q.front(); q.pop();
                A.push_back(r->val);
                for (auto e : r->children)
                    q.push(e);                
            }
            ans.push_back(A);
        }
        return ans;
    }
};