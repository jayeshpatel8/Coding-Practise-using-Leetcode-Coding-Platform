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
//0->1,3
//1->3
class Solution {
public:
    Node* cloneGraph(Node* node) {
      if (!node) return node;
      
      unordered_map<Node*,Node *> N;        
      return dfs(node, N);
        
    }

    Node* dfs(Node * node, unordered_map<Node*,Node *>& N){
        if (!node) return node;
        if (N.find(node) != N.end()) return N[node] ;
        Node *t = new Node(node->val);
        N[node]=t; 
        for (auto i : node->neighbors)
            t->neighbors.push_back(dfs(i,N));
        return t;    
    }
};