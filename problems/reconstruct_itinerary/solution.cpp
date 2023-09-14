class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> m;
        for (auto & t : tickets){
            m[t[0]].insert(t[1]);
        }
        vector<string> stack,ans;
        stack.push_back("JFK");
        while (!stack.empty()){
            auto u = stack.back();
            if (m[u].empty()){
                stack.pop_back();
                ans.push_back(u);
            }
            else{
                auto it = begin(m[u]);
                stack.push_back(*it);
                m[u].erase(it);
            }
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};