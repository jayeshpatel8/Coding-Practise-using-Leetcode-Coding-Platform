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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return    vector<vector<int>>();
        stack<TreeNode*> lvl1,lvl2,*lvl;
        vector<vector<int>> res;
        lvl1.push(root);
        lvl = &lvl1;
        bool r1=true;
        stack<TreeNode*> *l2 ;
        while(!lvl->empty())
        {
            
            vector<int> o;
               l2 = r1?&lvl2:&lvl1;
            {
                while (!lvl->empty())
                {TreeNode* r = lvl->top();lvl->pop();
                    if (r)
                    {
                        if (r->left ||r->right)
                        {
                            if (!r1){
                            l2->push(r->right);  
                            l2->push(r->left);                                
                            }
                            else{
                            l2->push(r->left);  
                            l2->push(r->right);
                            }
                        }
                        o.push_back(r->val);    
                    }
                }
                //lvl->clear();
                lvl= l2;
            }
            r1 =!r1;
            res.push_back(o);
        }
        return res;
    }
    
};