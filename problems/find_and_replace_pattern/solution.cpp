class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto &w : words){
            int map[128]={}, map2[128]={};
            int i=0;
            for (;i<w.size(); i++) 
            {
                auto c1= w[i],c2=pattern[i];
                if (!map[c1]){
                    if (!map2[c2])
                        map[c1]=c2,map2[c2]=1;
                    else
                        break;
                }
                else if (map[c1] != c2) break;
            }
            if (i == w.size()){
                ans.push_back(w);
            }
        }
        return ans;
    }
};