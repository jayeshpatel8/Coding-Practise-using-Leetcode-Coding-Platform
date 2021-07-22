#define MAX_LOGN 18
class TreeAncestor {
public:
    vector<vector<int>> jump;
    TreeAncestor(int n, vector<int>& parent) {
        jump = vector<vector<int>>(MAX_LOGN,vector<int>(n,-1));
        
        for(int i=0; i< n; i++)
            jump[0][i] = parent[i]; 
        
        for(int j=1; j< MAX_LOGN; j++)
            for(int i=1; i< n; i++){
                if (jump[j-1][i] != -1)
                    jump[j][i] = jump[j-1][jump[j-1][i]]; 
            }
    }
    
    int getKthAncestor(int node, int k) {
        int anscestor=node;
        for (int i=0; i<MAX_LOGN && (anscestor != -1) ; i++){
            if (k & (1 << i)){
                anscestor  =  jump[i][anscestor]; 
            }
        }
        return anscestor;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */