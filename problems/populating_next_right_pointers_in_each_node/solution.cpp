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
    Node* connect(Node* root, Node* prevl = NULL) {
        if (root && root->right){
            //root->right->next=NULL;
            root->left->next  =root->right;
            if (prevl) prevl->right->next = root->left, prevl=prevl->right;            
            connect(root->left,prevl);
            connect(root->right,root->left);
        }
        return root;
    }
};