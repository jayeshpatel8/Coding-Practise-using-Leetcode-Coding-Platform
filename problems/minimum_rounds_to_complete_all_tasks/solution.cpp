class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> cnt;
        for (auto i : tasks) cnt[i]++;
        int ans = 0;
        for (auto &[k,v]: cnt){
            if (v==1) return -1;
            ans += (v/3) + (v%3!=0);
        }
        return ans;
    }
};