class Solution {
public:
    string frequencySort(string s) {
        vector<int> f(256), idx(256);
        iota(begin(idx),end(idx),0);
        for (auto c : s) f[c]++;
        sort(begin(idx),end(idx),[&](auto a, auto b){return f[a] >f[b];});
        string ans;
        for (auto i : idx){
            if (f[i])
                ans += string(f[i],i);
            else 
                break;
        }
        return ans;
    }
};