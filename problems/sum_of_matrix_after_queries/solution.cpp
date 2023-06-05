class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> r(n,1),c(n,1);
        int r_cnt=n,c_cnt=n;
        long long ans = 0;
        for (int i1=queries.size()-1; i1>=0; i1--){
            auto & q = queries[i1];
            int t = q[0], i=q[1], v=q[2] ;
            
            if (t){
                if (c[i]){
                    ans += v * r_cnt; 
                    c[i]=0;
                    c_cnt--;
                }
            }
            else{
                if (r[i]){
                    ans += v * c_cnt; 
                    r[i]=0;
                    r_cnt--;
                }
            }
        }
        return ans;
    }
};