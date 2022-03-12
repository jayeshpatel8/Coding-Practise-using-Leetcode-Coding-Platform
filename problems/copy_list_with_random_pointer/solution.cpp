/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node*> m;
        Node * h = head;
        while(h){
            m[h]=new Node (h->val);
            h=h->next;
        }
        h = head;
        while(h){
            Node * h2 = m[h];
            h2->next = m[h->next];
            h2->random = m[h->random];
            h=h->next;
        }
        return m[head];
    }
};