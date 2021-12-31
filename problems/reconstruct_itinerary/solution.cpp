class Solution {
public:
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> m;
        for (auto &s : tickets)            
                m[s[0]].insert(s[1]);
        
         vector<string> trace(1, "JFK");
        while (!trace.empty()){
            string u = trace.back();
            if (m[u].empty()){
                ans.push_back(u);
                trace.pop_back();
            }
            else{
                auto it = m[u].begin();
                trace.push_back(*it);
                m[u].erase(it);
            }
        }
        reverse(begin(ans),end(ans));
        return ans;
    }

};