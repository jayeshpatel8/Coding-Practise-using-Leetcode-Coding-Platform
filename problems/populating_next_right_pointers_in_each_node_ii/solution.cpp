/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root ) return root;
        
      Node *r = root->next;

        while (r && !r->left && !r->right)
                r = r->next;
         r =  r? (r->left ? r->left:r->right):0;    
       
        if(root->right) { 
            root->right->next =r;
            if (root->left)root->left->next=root->right;
        }
        else if (root->left)root->left->next= r;
        connect(root->right);
        connect(root->left);
        
        return root;
    }
};