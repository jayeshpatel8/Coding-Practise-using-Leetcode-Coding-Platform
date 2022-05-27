class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<int> pos[10];
        for (int i=0; i<s.size(); i++)
            pos[s[i]-'0'].push_back(i);
        vector<int> cnt(10);
        for (int i=0; i<t.size(); i++){
            
            int d = t[i]-'0';
            if (cnt[d] >= pos[d].size() ) return false;
            for (int d1=0; d1<d; d1++){
                if (cnt[d1] < pos[d1].size() && pos[d1][cnt[d1]] < pos[d][cnt[d]])
                    return false;
            }
            cnt[d]++;
        }
        return true;
    }
};