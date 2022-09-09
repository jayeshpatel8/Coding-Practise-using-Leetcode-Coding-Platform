class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& P) {
        int def[100002]={};
        for (auto &i : P) def[i[0]] = max(def[i[0]],i[1]);
        for (int a = 100000; a>0; a--) def[a] = max(def[a],def[a + 1]);
        int ans = 0;
        for (auto &i : P){
            if (def[i[0] + 1] > i[1]) ans++;
        }
        return ans;
    }
};