class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector< long long>> path(26, vector<long long> (26,LLONG_MAX));
        for (auto i=0; i<changed.size(); i++){
            auto s = original[i]-'a', d = changed[i]-'a';
            path[s][d]=min<long long>(path[s][d] , cost[i]);
        }

        
        for (int k=0; k<26; k++)
            for (int i=0; i<26; i++)
                for (int j=0; j<26; j++){
                    if ( (path[i][k] != LLONG_MAX) && (path[k][j]  != LLONG_MAX) && (path[i][j] > path[i][k] + path[k][j])){
                        path[i][j] = path[i][k] + path[k][j];              
                    }
                }
        long long ans=0;
        for (int i=0; i<source.size(); i++){
            if (source[i] != target[i]){
                auto s = source[i]-'a',t=target[i]-'a';
                if (path[s][t] == LONG_MAX) return -1;
                ans += path[s][t];
            }
        }
        return ans;
    }
};
