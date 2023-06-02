class Solution {
public:

    int closestToTarget(vector<int>& arr, int target) {
        int v[19], sz = 1, ans = abs(target - arr[0]); v[0] = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            int u = arr[i], p = 1; v[0] &= u;
            for (int j = 1; j < sz; ++j) {
                int w = v[j] & u;
                if (w != v[p-1]) v[p++] = w;
            }
            if (u != v[p-1]) v[p++] = u;
            sz = p;
            for (int j=0; j<sz; j++)
                ans = min(ans, abs(target - v[j]));
        }
        return ans;
    }
};