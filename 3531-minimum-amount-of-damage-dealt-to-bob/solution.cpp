class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
         int n = damage.size();
        for (int i = 0; i < n; ++i) {
            health[i] = (health[i] + power - 1) / power;
        }
        vector<int> idx(n);
        iota(begin(idx),end(idx),0);
        sort(begin(idx),end(idx),[&](auto i, auto j){ return (health[i] * damage[j] <health[j] * damage[i]);});
        long long ans = 0;
        int time = 0;
        for (auto i : idx){
            time += health[i];
            ans += time * damage[i];
        }
        return ans;
    }
};
