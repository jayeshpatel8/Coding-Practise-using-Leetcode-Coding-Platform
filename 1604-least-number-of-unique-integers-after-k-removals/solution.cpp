class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> f;
        for (auto i : arr) f[i]++;
        int ans = 0;
        vector<int> s;
        
        for (auto &[k,v] : f) s.push_back(v),ans++;
        sort(begin(s),end(s));
        for (auto i : s){
            k-= i;
            if (k <0) return ans;
            ans--;
        }    
        return ans;
    }
};
