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
        if (!head) return head;
        Node * h = head, *nh;
        //Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
        //Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
        while (h){
            Node *t = new Node(0);
            *t = *h;
            h->next = t;
            h = t->next;
        }
        h = head;
        nh = head->next;
        while(h){
            Node *n = h->next;
            n->random = n->random? n->random->next:0;
            h = n->next;
        }
        h = head;
        while(h)
        {
            Node *n = h->next;
            h->next = n->next;
            n->next = h->next?h->next->next:0;
            
            h = h->next;
        }
        return nh;
    }
};