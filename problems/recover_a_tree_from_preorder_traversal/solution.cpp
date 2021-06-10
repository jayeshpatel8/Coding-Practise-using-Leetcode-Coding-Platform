/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int idx=0 , N;
    TreeNode* recoverFromPreorder(string s) {
        int pre[1000], depth[1000];
        int j=0,  n=s[0]-'0',c=0;
        pre[0] = n; depth[0]=0;
        for (int i=1; i<s.size(); i++){
            
            if (s[i] != '-')  {
                if (s[i-1] =='-') {
                    depth[j]=c; c=n=0;
                }
                n = (n * 10)+ s[i]-'0';
            }
            else {
                c++;
                if (s[i-1]!='-') pre[j++]=n;
            }
        }
        pre[j]=n;
        N= j;
       
       return dfs(pre,depth,0,j);   
    }
    
    TreeNode* dfs(int * pre, int * depth, int s , int e){
       
        if (s > e  ) return NULL;
        
        TreeNode* root  = new TreeNode(pre[idx++]);
        if (s ==e) return root;
        int i = s+2;
        while (i <= N && depth[i] >depth[idx] ) i++;
       
        root->left = dfs(pre,depth,s+1,i-1);
        root->right = dfs(pre,depth,i,e);
        return root;
    }
};