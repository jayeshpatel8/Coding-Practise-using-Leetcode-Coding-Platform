class Solution {
public:
int ans=0;
vector<int> m;
    int numTilePossibilities(string tiles) {
        m.resize(26);
        for (auto c : tiles) m[c-'A']++;
        dfs();
        return ans;
    }
    void dfs(){
        
        for (int i=0; i<26; i++){
            if (m[i] == 0)continue;
            m[i]--;
            dfs();ans++;
            m[i]++;
        }
    }
};
