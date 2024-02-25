class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int N=  nums.size();
        uf.resize(N,-1); sz.resize(N,1);
        unordered_map<int, int> idx;
        for (auto i =0; i<  nums.size(); i++){
            int n  = nums[i];
            for (int d=2; d*d<=n; d++){
                if (n%d==0){
                    if (idx.count(d)){
                        join(idx[d], i);
                    }
                    else idx[d]=i;
                }
                while (n%d==0) n/=d;
            }
            if (n!=1){
                if (idx.count(n)){
                        join(idx[n], i);
                    }
                else idx[n]=i;
            }
        }
        return sz[find(0)]==N;
    }
    vector<int> uf,sz;  
    int find(int i){
        return uf[i] == -1 ? i : uf[i] = find(uf[i]);
    }
    void join (int i, int j){
        int pi = find(i), pj = find(j);
        if (pi != pj){
            if (sz[pi] >= sz[pj]){
                swap(pi,pj);
            }
            uf[pi]=pj;
            sz[pj] += sz[pi];
        }
    }
};
