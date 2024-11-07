class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int cnt[32]={};

        for (auto i : candidates){
            for (int j=0;j<24; j++){
                if (i & (1<<j)) cnt[j]++;
            }
        }
        return *max_element(begin(cnt),end(cnt));
    }
};
