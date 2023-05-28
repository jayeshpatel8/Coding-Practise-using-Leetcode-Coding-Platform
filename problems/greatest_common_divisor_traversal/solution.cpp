class Solution {
public:
    vector<int> uf,sz;
    int find(int i){
        return uf[i] <0 ? i  : uf[i]=find(uf[i]);
    }
    void join (int i, int j){
        int pi= find(i),pj = find(j);
        if (pi != pj){
            if (sz[pi] > sz[pj])
                swap(pi,pj);
            uf[pi] = pj;
            sz[pj] +=sz[pi];
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int N = nums.size();
        if (N==1) return true;
        uf.resize(N,-1);
        sz.resize(N,1);

        unordered_map<int,int> idx;
        for (int i=0; i<N; i++){

            if (nums[i] == 1) return false;
            int n = nums[i];
            for (int d=2; d*d <=n; d++){
                if (n %d == 0){
                    if (idx.count(d))
                        join(idx[d],i);
                    else
                        idx[d]=i;
                }
                while (n%d == 0) n/=d;
            }
            if (n!=1)
                if (idx.count(n))
                    join(idx[n],i);
                else
                    idx[n]=i;
        }
        cout  << sz[find(0)];
        return sz[find(0)]== N;
    }
};