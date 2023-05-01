class Solution {
public:
struct video{
    long view=0;
    int id;
} ;
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& views) {
        unordered_map<string, video> m;
        long max_view=0;
        for (int i=0; i<c.size(); i++){
            if (!m.count(c[i])){
                m[c[i]] = {views[i],i};
                max_view = max<long>(max_view, views[i]);
            }
            else{
                auto &v = m[c[i]];
                v.view += views[i];
                max_view = max<long>(max_view, v.view);
                if (views[i] == views[v.id] ){
                    if( ids[i] < ids[v.id])
                        v.id=i;
                }
                else if (views[i] > views[v.id] )
                    v.id=i;
            }
        }
        vector<vector<string>> ans;
        for (auto &[cre,v] : m){
            if (max_view == v.view)
                ans.push_back({cre,ids[v.id]});
        }
        return ans;
    }
};