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
unordered_map<Node*,Node*> m;
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        auto * h = head;
        m[nullptr]=nullptr;
        while(h){
            m[h]=new Node(h->val);
            h=h->next;
        }
        h=head;        
        while(h){
            auto * c = m[h];
            c->next = m[h->next];
            c->random = m[h->random];
            h=h->next;
        }
        return m[head];
    }
};