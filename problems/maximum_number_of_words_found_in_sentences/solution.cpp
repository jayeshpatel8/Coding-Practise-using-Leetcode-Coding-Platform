class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for (auto & s : sentences){
            int cnt = 0;
            for (auto c : s)
                if (c ==' ') cnt++;
            ans = max(ans, 1 + cnt);
        }
        return ans;
    }
};