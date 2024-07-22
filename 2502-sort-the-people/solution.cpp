class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> idx(names.size()) ;
        iota(begin(idx),end(idx), 0);
        sort(begin(idx),end(idx), [&](auto a, auto b){
            return heights[a] > heights[b];
        });
        vector<string> ans;
        for (auto i : idx)
            ans.push_back(names[i]);
        return ans;
    }
};
