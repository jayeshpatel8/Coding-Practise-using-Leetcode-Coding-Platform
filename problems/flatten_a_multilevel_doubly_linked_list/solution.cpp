/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head, Node * n=NULL) {
        if (!head) return head;
        
        Node * h = head;
        while(h){
            if (h->child){
                Node* next = h->next;
                h->next = flatten(h->child,next);
                h->next->prev = h;
                h->child = NULL;                   
            }
            if (!h->next){ 
                h->next = n;
               if (n) n->prev = h;
                return head;
            }
            h = h->next;
        }
        return head;
    }
};