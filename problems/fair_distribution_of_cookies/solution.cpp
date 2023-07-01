class Solution {
public:

    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX, avg = accumulate(begin(cookies),end(cookies),0) / k;

        vector<int> ch(cookies.size());
        function<void(int,int)> dfs = [&] (int i, int sum) {
            if (i >= cookies.size() || sum > ans){
                ans= min(ans,sum); return;
            }
            for (int j=0; j<k; j++){
                if (ch[j] >= avg) continue;
                if (j>0 && ch[j] == ch[j-1]) continue;
                ch[j] += cookies[i];
                dfs(i+1,max(sum , ch[j]));
                ch[j] -= cookies[i];
            }
        }   ;    
        dfs(0,0);
        return ans;
    }
};