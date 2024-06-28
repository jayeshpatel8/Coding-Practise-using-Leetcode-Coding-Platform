class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> ind(n);
        for (auto & r : roads){
            ind[r[0]]++;ind[r[1]]++;
        }
        sort(begin(ind), end(ind));
        long long ans = 0;
        for (long long i=n-1; i>=0; i--){
            ans += (i+1) * ind[i];
        }
        return ans;
    }
};
