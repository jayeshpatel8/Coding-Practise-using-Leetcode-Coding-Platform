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
        Node * t = head;
        unordered_map<Node *, Node *> m;
        while (t != NULL){
            m[t] = new Node(t->val);
            t=t->next;
        }
        t=head;

        while (t != NULL){
            m[t]->random = m[t->random];
            m[t]->next=m[t->next];
            t=t->next;
        }
        return m[head];
    }
};
