class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<pair<int,int>> gp(p.size());
        for (int i=0; i<p.size(); i++)
            gp[i] = {g[i],p[i]};
        sort(begin(gp),end(gp),[](auto & a, auto &b){return a.first > b.first; });
        int d=-1, ans=0;
        for (auto & [gt,pt] : gp){
            d+=pt;
            ans = max(ans, d+gt+1);
        }
        return ans;
    }
};