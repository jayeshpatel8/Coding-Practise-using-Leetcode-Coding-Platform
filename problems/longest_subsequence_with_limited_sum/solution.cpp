class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& Q) {
        int m  = Q.size(), n = nums.size();
        vector<int> psum(n+1), ans(m);
        sort(begin(nums),end(nums));
        for (int i=0; i<n; i++)
            psum[i+1] = psum[i] + nums[i];
        for (int i=0; i<m ; i++){
            ans[i] = upper_bound(begin(psum), end(psum), Q[i]) - begin(psum)-1;
        }
        return ans;
    }
    vector<int> answerQueries2(vector<int>& nums, vector<int>& Q) {
        int m  = Q.size();
        vector<int> idx(m), ans(m);
        iota(begin(idx),end(idx),0);
        sort(begin(idx),end(idx),[&](auto &a, auto &b){ return Q[a]<Q[b];});
        sort(begin(nums),end(nums));
        for (int i=0, j =0, psum = 0, n = nums.size(); i<m ; i++){
            while (j<n && (psum + nums[j] <= Q[idx[i]])) {
                psum += nums[j++];
            }

            ans[idx[i]]=j;
        }
        return ans;
    }
};