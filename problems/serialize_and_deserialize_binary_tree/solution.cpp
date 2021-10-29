/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
     // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    int i=0;
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return mdeserialize(data);
    }
    TreeNode* mdeserialize(string& data) {
        if (data[i]=='#') {
            i +=2;
            return NULL;
        }
        TreeNode* root = new TreeNode(getval(data));
        root->left = mdeserialize(data);
        root->right = mdeserialize(data);
        return root;
    }
    int getval(string & data){
        int j =  data.find(",",i);
        int ans = stoi(data.substr(i,j-i));     
        i =j+1;
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));