class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> map;
        int half = arr.size()/2;
        for (auto i : arr) map[i]++;
        vector<int> cnt;
        for (auto &[k,v] : map) cnt.push_back(v);
        int size = 0,ct=0;
        sort(begin(cnt),end(cnt));
        for (auto it = rbegin(cnt); it!= rend(cnt); it++){
            size += *it;
            ++ct;
            if (size >= half) return ct;
            
        }
        return ct;
    }
};