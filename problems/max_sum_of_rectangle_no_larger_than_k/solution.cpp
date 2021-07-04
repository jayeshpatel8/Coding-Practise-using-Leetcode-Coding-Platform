class Solution {
public:
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size() , n  = matrix[0].size();
        int ans = INT_MIN;
        for (int c=0; c<n; c++){
            vector<int> sum(m);
            
            for (int j=c; j<n; j++){
                int psum=0, msum=INT_MIN;
                for (int i=0; i<m; i++){
                    sum[i] +=matrix[i][j];
                    psum = max(psum +sum[i], sum[i]);
                    msum = max(msum,psum);
                }
                if (msum <= k) {ans = max(ans,msum); continue;}
                set<int> s={0};
                psum=0;
                for (auto i : sum){
                    psum +=i;
                    auto it  = s.lower_bound(psum - k);
                    if (it != end(s)){
                        ans = max(ans,psum-*it);
                    }
                    s.insert(psum);
                }
            }
        }
        return ans;
    }
};