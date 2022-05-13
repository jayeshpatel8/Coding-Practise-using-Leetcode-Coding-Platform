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
        if(root==NULL)
            return NULL;
        queue<Node *> q;
        q.push(root);        
        
        //BFS
        while (!q.empty()){
            int sz = q.size()-1;
            
            while (sz-- > 0 ){
                auto * t =  q.front(); q.pop();
                t->next = q.front();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            auto * t =  q.front(); q.pop();
            t->next = NULL;
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        return root;
    }
    Node* connect2(Node* root) {
        dfs(root,NULL);
        return root;
    }
    void dfs(Node * root, Node * parent){
        if (!root) return ;
        root->next = parent ?  : parent;
        auto * t =  root->next;
        if (root->right ||  root->left){
            while (t){
                if (t->left || t -> right){
                    t = (t->left ? t->left : t->right);
                    break;
                }
                t=t->next;
            }                    
        }
        dfs(root->right, t);    
        dfs(root->left, root->right ? root->right : t);    
    }
};