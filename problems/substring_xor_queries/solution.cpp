class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
       unordered_map<int, vector<int>> m;
        for (int i = 0; i<s.size(); i++){
            long long val = 0;
            for (int j=i; j<min<int>(s.size(), i+30); j++){
                val =( val << 1) + (s[j]=='1');
                if (!m.count(val))
                    m[val] = {i,j};
                if (s[i] == '0')
                    break;                
            }
        }
        vector<vector<int>> ans;
        for (auto &q : queries){

            if (auto it = m.find(q[0] ^ q[1]); it != end(m))
                ans.push_back(it->second);
            else
                ans.push_back({-1,-1});
        }
        return ans;
    }
};