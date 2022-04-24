class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& per) {
        int n=f.size();
        vector<array<int,2>> s(n*2 +per.size());
        for (int i=0;i<n; i++){
            s[i]={f[i][0],1};
            s[n+i]={f[i][1]+1,-1};
        }
        for (int i=0; i<per.size(); i++)
            s[2*n+i]={per[i],i-50000-2};
        sort (begin(s),end(s), [](auto &i, auto &j){return i[0] == j[0] ? i[1] > j[1] : i[0] < j[0] ;});
        
        vector<int> ans(per.size());
        for (int cnt=0, i=0; i<s.size(); i++){
            if (s[i][1] >-2)
                cnt += s[i][1];
            else
                ans[s[i][1]+50002] = cnt;        
        }
        return ans;
        
    }
};