class Solution {
public:
    
    string tree2str(TreeNode* root) {
        string s = to_string(root->val);
    

        if (root->left){
            s += '(' + tree2str(root->left) + ')';        
            if(root->right)
                s += '(' + tree2str(root->right) + ')';       
        }

        else if (root->right){
            s+="()";
            s += '(' + tree2str(root->right) + ')';                   
        }
        return s;
    }
};
