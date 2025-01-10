class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int w2[126]={};
        for (auto &w : words2){
            int w1[126]={};
            for (auto &c : w)
                w1[c]++;
            for (int i='a';i<='z'; i++){
                w2[i] = max(w2[i],w1[i]);
            }
        }
        vector<string> ans;
        for (auto &w : words1){
            int w1[126]={};
            for (auto &c : w) w1[c]++;
            int i='a';
            for (;i<='z'; i++)
                if (w1[i] < w2[i])break;
            if (i >'z')
             ans.push_back(w);
        }
        return ans;
    }
};
