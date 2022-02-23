/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>map;
    Node* cloneGraph(Node* node) {
        return dfs(node);
        
    }
    Node * dfs(Node * node){
        if (!node ) return node;
        if (map.count(node)) return map[node];
        Node * n = new Node(node->val);
        map[node] = n;
        for ( auto &i : node->neighbors){                        
            n->neighbors.push_back(dfs(i));
        }
        return n;
    }
};