class Solution {
public:
    int uf[10001] = {}, rank[10001];
    vector<bool> areConnected(int n, int th, vector<vector<int>>& qu) {
        if (th == 0) return vector<bool>(qu.size(),true);
        for (int i=1; i<=th; i++) rank[i]=1;
        for ( int i =th+1; i<=n; i++){
            rank[i]=1;
            connect(i,i);
            for (int j=2; j*j<=i; j++){
                if (i % j == 0){
                    if (j > th)
                        connect(i,j);
                    if (i/j > th)
                        connect(i,i/j);
                }                
            }
        }
        vector<bool> ans (qu.size());
        for ( int i=0;i<qu.size(); i++){
            int u = qu[i][0], v = qu[i][1];
            ans[i] = (find(u) == find ( v));                
        }
        return ans;
    }
    void connect( int i, int j){
    
        int p1 = find( i),p2 = find( j);
        if (p1 != p2){
             //uf[p1]=p2;
            
            if (rank[p1] < rank[p2])
                uf[p1]=p2, rank[p2]+=rank[p1];
            else
                uf[p2]=p1, rank[p1]+=rank[p2];
                
        }
    }
    int find(int i){
        return uf[i] == 0? i : uf[i] = find ( uf[i]);
    }
};