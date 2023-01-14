class Solution {
public:
    vector<int> uf, sz;
    int find (int a){
        return uf[a] < 0? a : uf[a]=find(uf[a]);
    }
    void merge(int a, int b){
        auto pa= find(a), pb =find(b);
        if (pa != pb){
            if (sz[pa]>sz[pb])
                uf[pa]=pb, sz[pb] +=sz[pa];
            else
                uf[pb]=pa, sz[pa] +=sz[pb];            
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        uf.resize(26,-1);
        sz.resize(26);
        for (int i=0; i<s1.size(); i++)
            merge(s1[i]-'a',s2[i]-'a');
        vector<int> smallest(26);
        for (int i=0; i<26; i++){
            int pi= find(i);
            for (int j=0; j<26; j++){
                if ( find(j) == pi) {
                    smallest[i]=j; break;
                }
            }
        }
        string ans;
        for (auto c : baseStr)
            ans +=(smallest[c-'a']+'a');
        return ans;
    }
};