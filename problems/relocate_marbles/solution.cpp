class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int,int> m;
        for(auto i : nums) m[i]=1;
        for (int i=0; i<moveFrom.size(); i++){
            m.erase(moveFrom[i]);
            m[moveTo[i]]=1;
            
        }
        vector<int> ans;
        for (auto &[k,v] : m) ans.push_back(k);
        sort(begin(ans),end(ans));
        return ans;
    }
};