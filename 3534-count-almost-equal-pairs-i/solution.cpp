class Solution {
public:
    int countPairs(vector<int>& nums) {
        vector<string> s;
        for (auto i : nums) s.push_back(to_string(i));
        sort(begin(s),end(s),[&](auto & a, auto &b){ return a.size() < b.size();});
        unordered_map<int,vector<int>> m;
        int ans = 0;
        for (auto i=0; i<s.size(); i++){
            auto s1 = s[i];
            int n = stoi(s1);
            set<int> idx;
            if (m.count(n)) {
                for (auto i1: m[n]) idx.insert(i1);
            } 
            for (int i=0; i<s1.size(); i++){

                for (int j = i+1; j<s1.size(); j++){
                    swap(s1[i],s1[j]);
                    int n1= stoi(s1);
                    if (m.count(n1)) {
                        for (auto i1: m[n1]) idx.insert(i1);
                    }
                    swap(s1[i],s1[j]);    
                }
            }
            m[n].push_back(i);
            ans += idx.size();
        }
        return ans;
    }
};
