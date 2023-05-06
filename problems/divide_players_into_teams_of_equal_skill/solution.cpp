class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = accumulate(begin(skill),end(skill),0);
        int N  = skill.size();
        int ts = sum/ (N/2);
        if (ts * (N/2) != sum) return -1;
        int f[1001]={};
        
        for (auto i : skill) f[i]++;
        
        long long ans = 0;

        for (int i=1 ,n= min(1000,ts); i<=n; i++){
            if (!f[i]) continue;
            int rem  = ts - i;
            if (f[i] != f[rem]) return -1;
            
            ans += (long)f[i] / (i==rem ? 2 : 1)  * (i* rem);
            f[rem]=0;
        }
        return ans;
    }
};