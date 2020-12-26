class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int kSize = rains.size();
        constexpr int kDoNothing = -1;
        constexpr int kNone = 0;
        constexpr int kAny = 1;
        vector<int> next(kSize, kDoNothing);
        
        unordered_map<int, int> current;
        for (int i=0; i<kSize; ++i) {
            int lake = rains[i];
            if (lake != kNone) {
                auto it = current.find(lake);
                if (it != current.end()) {
                    next[it->second] = i;
                }
                current[lake] = i;
            }
        }
        
        vector<int> res;
        res.reserve(kSize);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        
        for (int i=0; i<kSize; ++i) {
            if (!q.empty()) {
                auto [day, lake] = q.top();
                if (i >= day) {
                    return vector<int>();
                }
            }
            
            if (rains[i] > 0) {
                res.push_back(kDoNothing);
                if (next[i] >= 0) q.push(make_pair(next[i], rains[i]));
            }
            else {
                if (q.empty()) {
                    res.push_back(kAny);
                }
                else {
                    auto [day, lake] = q.top();
                    q.pop();
                    res.push_back(lake);
                }
            }
        }
        
        return res;
    }
};
#if  0
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        int N = rains.size();
        vector<int> res(N, 1);
        map<int,int> m;
        set<int> dry;       
        
        for (int i=0;i < N; i++){
            auto e = rains[i];
            if (e){
                if(i>0 && e == rains[i - 1])
                    return {};
                auto it = m.find(e);
                if (it != m.end()) {

                    auto t = dry.lower_bound(it->second);
                    if ( t != dry.end() ){
                        res[*t]=e; 
                        dry.erase(t);
                    }
                    else
                        return {};
                }
                m[e]=i;
                res[i]=-1;
            }
            else  // dry
                dry.insert(i);
        }
        
        return res;
    }
};
#endif