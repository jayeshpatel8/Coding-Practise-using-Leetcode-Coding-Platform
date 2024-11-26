class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> ind(n,0);

        for (auto e : edges) ind[e[1]]++;

        int champ_e = -1, champ= 0;

        for (int i=0; i < n; i++){
            if (ind[i] == 0){
                champ_e = i, champ++;
            }
        }
        return champ > 1? -1 : champ_e ;
    }
};
