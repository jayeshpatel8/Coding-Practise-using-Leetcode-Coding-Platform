class Solution {
public:
    int M,N;
    vector<int> constructDistancedSequence(int n) {
        N= 1+2*(n-1);
        vector<int> res(N,0);
        vector<int> vis(n+1,0);
        M=n;
        cDS(res,0,vis);
        return res;
    }
    bool cDS(vector<int> &res,int i,vector<int> & vis){
        if (i>= res.size()) return true;
        if (res[i]) return cDS(res,i+1,vis);
        for (int j=M; j>0; j--){
            if (!vis[j]  ){
                if (j!=1 && (i+j>=N || res[i+j] )) continue;
                res[i] = j;
                vis[j]=1;
                if (j!=1 ) res[i+j]=j; 
                if (cDS(res,i+1,vis)) return true;
                vis[j]=0;res[i] = 0;
                if (j!=1 ) res[i+j]=0;
                
            }
        }
        return false;
    }
};