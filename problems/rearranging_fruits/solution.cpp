class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<long long,int> cnt;
        for (auto c : basket1) cnt[c]++;
        for (auto c : basket2) cnt[c]--;
        long long ans = 0;
        int swap = 0;
         
        for (auto &[k,v] : cnt){
            if (v&1) return -1;
            swap += max(0, v/2);
        }
        for (auto &[k,v] : cnt){
            if (swap==0) return ans;
            auto taken = min (swap, abs(v)/2);
            ans += taken * min(k, begin(cnt)->first * 2);
            swap -=taken;
        }
        return ans;
    }
};