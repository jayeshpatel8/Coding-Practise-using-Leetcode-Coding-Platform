class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(begin(logs),end(logs),[&](auto &a, auto &b){return a[1] < b[1];});
        vector<int> ids(queries.size()), ans(ids),ser(n+1);
        iota(begin(ids),end(ids),0);
        sort(begin(ids),end(ids),[&](auto a, auto b){ return queries[a] <queries[b];});
        for (int i = 0, l = 0 ,r = 0, cnt = 0; i < queries.size(); i++){
            int b = queries[ids[i]], a = b- x;
            for (; l<logs.size() && logs[l][1] < a; l++)
                if (--ser[logs[l][0]] == 0) cnt--;

            for (; r<logs.size() && logs[r][1] <= b; r++)
                if (ser[logs[r][0]]++ == 0) cnt++;
            
            ans[ids[i]]= n - cnt;
        }
        return ans;
    }
};