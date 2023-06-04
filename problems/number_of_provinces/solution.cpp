class Solution {
public:
vector<int> uf,sz;
    int find(int i){
        return uf[i] < 0 ? i : uf[i] = find (uf[i]);
    }
    void join(int i , int j){
        int pi = find (i), pj = find(j);
        if (pi != pj){
            if (pi > pj) swap(pi,pj);
            uf[pi] = pj;
            sz[pj] += sz[pi];
        }
    }
    int findCircleNum(vector<vector<int>>& isConn) {
        int N =  isConn.size();
        uf.resize(N,-1);
        sz.resize(N,1);
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                if (isConn[i][j])
                    join(i,j);
        return count(begin (uf),end(uf),-1);
    }
};