class Solution {
public:
    string oddString(vector<string>& words) {
        int n =  words[0].size();
        int j = 1;
        for (int i=1; i<n; i++){
            unordered_map<int,int> diff;
            for (auto  l=0; l< words.size(); l++){
                auto &w = words[l];
                auto d =  (w[i] - w[i-1]);
                if (!diff.count(d)) diff[d]=l;
                else
                    diff[d]=INT_MAX;
            }
            for (auto &[k,v] : diff){
                if (v != INT_MAX) return words[v];
            }
        }      
        return {};
    }
};