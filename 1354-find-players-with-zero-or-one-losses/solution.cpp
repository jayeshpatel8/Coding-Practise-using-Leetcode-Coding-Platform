class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> w,l;
        for (auto &i : matches){
            w[i[0]]++,l[i[1]]++;
        }
        vector<int> wl,ll1;
        for (auto &[k,v] : w){
            if (l.count(k)){
                if (l[k]==1) ll1.push_back(k);
            }
            else wl.push_back(k);
        }
        for (auto &[k,v] : l){
            if (v==1){
                if (w.count(k)==0) ll1.push_back(k);
            }

        }        
        sort(begin(wl),end(wl));
        sort(begin(ll1),end(ll1));
        return {wl,ll1};
    }
};
