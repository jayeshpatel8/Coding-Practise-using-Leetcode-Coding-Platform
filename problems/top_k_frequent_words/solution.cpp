class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> f;
        for (auto &w : words) f[w]++;
        vector<pair<string,int>> s;
        for (auto &[str,freq] : f){
            s.push_back({str,freq});
        }
        sort(begin(s),end(s),[](auto &a, auto &b){
            if ( a.second != b.second)
                return a.second > b.second;
            return a.first < b.first;
        });
        vector<string> ans;
        for (auto &i : s)
            if (k--)
                ans.push_back(i.first);
            else break;
        return ans;
    }
};