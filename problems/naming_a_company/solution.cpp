class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        unordered_set<string> st(begin(ideas),end(ideas));
        int f[128][128]={}, N = ideas.size();
        for (auto &s : ideas){
            for (int c='a',oc= s[0]; c<='z'; s[0] = ++c){
                s[0] = c;
                if (st.count(s)==0)
                    f[oc][c]++;                
            }
        }
        for (int i='a'; i<='z'; i++) for (int j=i+1; j<='z'; j++)
                if (f[i][j] && f[j][i])
                    ans+=(f[i][j] *f[j][i])*2LL ;

        return ans;
    }
};