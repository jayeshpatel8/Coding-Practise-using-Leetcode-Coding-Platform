class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& qu) {
        vector<int> sorted_cnt(n+1),freq(n+1),ans(qu.size());
        vector<unordered_map<int,int>> map(n+1);
        for (auto &e : edges){
            sorted_cnt[e[0]]=++freq[e[0]];
            sorted_cnt[e[1]]=++freq[e[1]];
            ++map[min(e[0],e[1])][max(e[0],e[1])];
        }
        sort(begin(sorted_cnt), end(sorted_cnt));


        for ( int k=0; k<qu.size(); k++){
            for (int i=1, j = n;i<j;){
                if (sorted_cnt[i] + sorted_cnt[j] > qu[k])
                    ans[k] += (j--) - i;
                else
                    i++;
            }
            
            for (int i=1;i<=n; i++){
                for (auto &[j , cnt] : map[i]){
                    if (freq[i] + freq[j] > qu[k] && freq[i] + freq[j] <= qu[k] +cnt)
                        --ans[k];
                }
            }
        }
        return ans;
    }

};