/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid,0, grid.size()-1,0);
    }
    Node * dfs(vector<vector<int>>& grid, int c1, int c2, int r1)
    {
        int n  =  c2-c1;    
        Node *ans = new Node();    
        if (n<=0){
            ans->isLeaf = 1;
            ans->val = grid[r1][c1];
 
            return ans;
        }
        int cnt = 0;

                ans->topRight = dfs(grid,c1 + (n/2)+1,c2, r1);
                ans->topLeft = dfs(grid,c1,c1+ (n/2), r1);
                ans->bottomLeft = dfs(grid,c1,c1+ (n/2), r1 + (n/2)+1);
                ans->bottomRight = dfs(grid,c1 + (n/2)+1,c2, r1 + (n/2)+1);
                ans->isLeaf  = ans->topRight->isLeaf &&ans->topLeft->isLeaf && ans->bottomLeft->isLeaf &&ans->bottomRight->isLeaf;

                if ( ans->isLeaf ){
                    cnt += (ans->topRight->val==0 )+(ans->topLeft->val==0) + (ans->bottomLeft->val==0) +(ans->bottomRight->val==0);
                    if (cnt > 0 && cnt <4)
                        ans->isLeaf = 0;
                    ans->val = grid[r1][c1];
                }   
                if ( ans->isLeaf )    
                ans->topRight= ans->topLeft= ans->bottomLeft= ans->bottomRight = nullptr;    

        return ans;
    }




};