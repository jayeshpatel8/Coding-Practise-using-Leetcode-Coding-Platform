class Solution {
public:
    long long maximumBeauty(vector<int>& fl, long long nf, int target, int full, int partial) {
        sort(begin(fl),end(fl));
        long long n= fl.size(), filled=0;
        for (int i=n-1; i>=0 && target <= fl[i]; i--)
            filled++;
        
        if (filled==n) return full * filled;
        
        n -=filled;
        
        long long sum = accumulate(begin(fl),begin(fl)+n,0LL), cur = full*filled, ans;
        int last=n-1;
        auto cost = [&](){
            return (long long) fl[last] * (last + 1) - sum;
        };
        while (last >=0  && (nf < cost()) ) sum -= fl[last--];
        long long min_f = min<long long>(target-1, fl[last] + (nf - cost()) / (last+1));
        ans = cur + min_f * partial;
        for (int i=n-1; i>=0 ; i--){
            cur += full;
            nf  -= target -fl[i];
            if (nf < 0)
                    break;

            while (last >=0  && (last >=i || nf < cost()) ) sum -= fl[last--];
            
            if (last == -1){
                ans = max(ans, cur);
                break;
            }
            min_f = min<long long>(target-1, fl[last] + (nf - cost()) / (last+1));
            ans = max(ans, cur + min_f * partial);
        }
        return ans = max(ans, filled * full);
    }
};